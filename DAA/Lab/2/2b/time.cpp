#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <stack>
using namespace std::chrono;
using namespace std;

int squaredDistance(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) +
           (p1.second - p2.second) * (p1.second - p2.second);
}

long long angle(pair<int, int> p, pair<int, int> p0) {
    return atan2(p.second - p0.second, p.first - p0.first);
}

// Function to sort points based on polar angle using atan2
vector<pair<int, int>> sortByPolarAngle(int p0Index, vector<pair<int, int>>& points) {
    pair<int, int> p0 = points[p0Index];
    
    vector<pair<int, int>> sortedPoints;
    for (int i = 0; i < points.size(); i++) {
        if (i != p0Index) sortedPoints.push_back(points[i]);
    }

    sort(sortedPoints.begin(), sortedPoints.end(), [&](pair<int, int> a, pair<int, int> b) {
        long long angleA = angle(a, p0);
        long long angleB = angle(b, p0);
        if (fabs(angleA - angleB) < 1e-9) { 
            return squaredDistance(p0, a) > squaredDistance(p0, b);
        }
        return angleA < angleB; 
    });

    sortedPoints.insert(sortedPoints.begin(), p0);
    return sortedPoints;
}

bool isNonLeftTurn(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int cross = (p2.first - p1.first) * (p3.second - p1.second) -
                (p2.second - p1.second) * (p3.first - p1.first);
    return cross < 0; 
}

vector<pair<int, int>> graham(vector<pair<int, int>> graph) {
    auto it = min_element(graph.begin(), graph.end(), [](const auto& a, const auto& b) {
        return (a.second < b.second) || (a.second == b.second && a.first < b.first);
    });
    int po = distance(graph.begin(), it);
    
    vector<pair<int, int>> sorted = sortByPolarAngle(po, graph);
    stack<pair<int, int>> st;

    for (int i = 0; i < 3; i++) {
        st.push(sorted[i]);
    }

    pair<int, int> top, next_to_top;
    for (int i = 3; i < sorted.size(); i++) {
        while (st.size() > 1) {
            top = st.top();
            st.pop();
            next_to_top = st.top();
            if (!isNonLeftTurn(next_to_top, top, sorted[i])) {
                st.push(top);
                break;
            }
        }
        st.push(sorted[i]);
    }

    vector<pair<int, int>> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

pair<int, int> mid;

// determines the quadrant of a point
// (used in compare())
int quad(pair<int, int> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}

// Checks whether the line is crossing the polygon
int orientation(pair<int, int> a, pair<int, int> b,
                pair<int, int> c)
{
    int res = (b.second-a.second)*(c.first-b.first) -
            (c.second-b.second)*(b.first-a.first);

    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

// compare function for sorting
bool compare(pair<int, int> p1, pair<int, int> q1)
{
    pair<int, int> p = make_pair(p1.first - mid.first,
                                p1.second - mid.second);
    pair<int, int> q = make_pair(q1.first - mid.first,
                                q1.second - mid.second);

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.second*q.first < q.second*p.first);
}

// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
vector<pair<int, int>> merger(vector<pair<int, int> > a,
                            vector<pair<int, int> > b)
{
    // n1 -> number of points in polygon a
    // n2 -> number of points in polygon b
    int n1 = a.size(), n2 = b.size();

    int ia = 0, ib = 0;
    for (int i=1; i<n1; i++)
        if (a[i].first > a[ia].first)
            ia = i;

    // ib -> leftmost point of b
    for (int i=1; i<n2; i++)
        if (b[i].first < b[ib].first)
            ib=i;

    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(b[indb], a[inda], a[(inda+1)%n1]) >=0)
            inda = (inda + 1) % n1;

        while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0)
        {
            indb = (n2+indb-1)%n2;
            done = 0;
        }
    }

    int uppera = inda, upperb = indb;
    inda = ia, indb=ib;
    done = 0;
    int g = 0;
    while (!done)//finding the lower tangent
    {
        done = 1;
        while (orientation(a[inda], b[indb], b[(indb+1)%n2])>=0)
            indb=(indb+1)%n2;

        while (orientation(b[indb], a[inda], a[(n1+inda-1)%n1])<=0)
        {
            inda=(n1+inda-1)%n1;
            done=0;
        }
    }

    int lowera = inda, lowerb = indb;
    vector<pair<int, int>> ret;

    //ret contains the convex hull after merging the two convex hulls
    //with the points sorted in anti-clockwise order
    int ind = uppera;
    ret.push_back(a[uppera]);
    while (ind != lowera)
    {
        ind = (ind+1)%n1;
        ret.push_back(a[ind]);
    }

    ind = lowerb;
    ret.push_back(b[lowerb]);
    while (ind != upperb)
    {
        ind = (ind+1)%n2;
        ret.push_back(b[ind]);
    }
    return ret;

}

vector<pair<int, int>> bruteHull(vector<pair<int, int>> a)
{
    // Take any pair of points from the set and check
    // whether it is the edge of the convex hull or not.
    // if all the remaining points are on the same side
    // of the line then the line is the edge of convex
    // hull otherwise not
    set<pair<int, int> >s;

    for (int i=0; i<a.size(); i++)
    {
        for (int j=i+1; j<a.size(); j++)
        {
            int x1 = a[i].first, x2 = a[j].first;
            int y1 = a[i].second, y2 = a[j].second;

            int a1 = y1-y2;
            int b1 = x2-x1;
            int c1 = x1*y2-y1*x2;
            int pos = 0, neg = 0;
            for (int k=0; k<a.size(); k++)
            {
                if (a1*a[k].first+b1*a[k].second+c1 <= 0)
                    neg++;
                if (a1*a[k].first+b1*a[k].second+c1 >= 0)
                    pos++;
            }
            if (pos == a.size() || neg == a.size())
            {
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }

    vector<pair<int, int>>ret;
    for (auto e:s)
        ret.push_back(e);

    // Sorting the points in the anti-clockwise order
    mid = {0, 0};
    int n = ret.size();
    for (int i=0; i<n; i++)
    {
        mid.first += ret[i].first;
        mid.second += ret[i].second;
        ret[i].first *= n;
        ret[i].second *= n;
    }
    sort(ret.begin(), ret.end(), compare);
    for (int i=0; i<n; i++)
        ret[i] = make_pair(ret[i].first/n, ret[i].second/n);

    return ret;
}

vector<pair<int, int>> divide(vector<pair<int, int>> a)
{
    // If the number of points is less than 6 then the
    // function uses the brute algorithm to find the convex hull
    if (a.size() <= 5)
        return bruteHull(a);

    // left contains the left half points
    // right contains the right half points
    vector<pair<int, int>>left, right;
    for (int i=0; i<a.size()/2; i++)
        left.push_back(a[i]);
    for (int i=a.size()/2; i<a.size(); i++)
        right.push_back(a[i]);

    // convex hull for the left and right sets
    vector<pair<int, int>>left_hull = divide(left);
    vector<pair<int, int>>right_hull = divide(right);

    // merging the convex hulls
    return merger(left_hull, right_hull);
}

vector<pair<pair<int,int>,pair<int,int>>> brute(vector<pair<int,int>>graph){
    vector<pair<pair<int,int>,pair<int,int>>> ans;
    int foundhull, vx, vy,v2x,v2y;
    for (int i = 0; i < graph.size(); i++){
        for (int j = i+1; j < graph.size(); j++){
            foundhull = 0;
            vx = graph[j].first - graph[i].first;
            vy = graph[j].second - graph[i].second;
            int up=0, down=0;
            for(int k = 0 ; k<graph.size() ; k++){
            v2x = graph[k].first - graph[i].first;
            v2y = graph[k].second - graph[i].second;
            
            int check = (vx*v2y) - (vy*v2x);
            
            if(check>0)
                up++;
            if(check<0)
                down++;
            }
            if(up>0 && down>0){
                continue;
            }
            else{
                ans.push_back(make_pair(graph[i],graph[j]));
            }
            
        }
    }
    return ans;
}

int main() {
    // Open the output file for storing the times
    ofstream file("time.txt");
    file << "Number of Points, Graham Scan Time (ns), Brute Force Time (ns), Divide and Conquer Time (ns)\n";

    srand(time(NULL));
    vector<pair<int, int>> graph;

    // Initial set of 4 random points
    for (int i = 0; i < 4; ++i) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));
    }

    // Measure the time for the first iteration (4 points)
    auto start1 = high_resolution_clock::now();
    vector<pair<int, int>> ans = graham(graph);
    auto end1 = high_resolution_clock::now();
    long long graham_time = duration<long long, nano>(end1 - start1).count();
    
    start1 = high_resolution_clock::now();
    vector<pair<pair<int, int>, pair<int, int>>> brute_ans = brute(graph);
    auto end2 = high_resolution_clock::now();
    long long brute_time = duration<long long, nano>(end2 - start1).count();

    start1 = high_resolution_clock::now();
    ans = divide(graph);
    auto end3 = high_resolution_clock::now();
    long long dc_time = duration<long long, nano>(end3 - start1).count();

    file << 4 << " " << graham_time << " " << brute_time << " " << dc_time << "\n";

    // Iterate from 5 points to 100 points
    for (int numPoints = 5; numPoints <= 100; ++numPoints) {
        // Add one new random point to the existing set
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));

        // Create copies of the graph to prevent modifications
        vector<pair<int, int>> graph_copy = graph;
        vector<pair<pair<int, int>, pair<int, int>>> brute_copy = brute(graph_copy);

        // Measure the time taken for each algorithm with the new set of points
        start1 = high_resolution_clock::now();
        ans = graham(graph_copy);
        end1 = high_resolution_clock::now();
        graham_time = duration<long long, nano>(end1 - start1).count();

        graph_copy = graph; // Reset to the original graph

        start1 = high_resolution_clock::now();
        brute_copy = brute(graph_copy);
        end2 = high_resolution_clock::now();
        brute_time = duration<long long, nano>(end2 - start1).count();

        graph_copy = graph; // Reset to the original graph

        start1 = high_resolution_clock::now();
        sort(graph_copy.begin(),graph_copy.end());
        ans = divide(graph_copy);
        end3 = high_resolution_clock::now();
        dc_time = duration<long long, nano>(end3 - start1).count();

        file << numPoints << " " << graham_time << " " << brute_time << " " << dc_time << "\n";
    }

    // Close the file
    file.close();
    cout << "Times saved to time.txt" << endl;
    
    return 0;
}