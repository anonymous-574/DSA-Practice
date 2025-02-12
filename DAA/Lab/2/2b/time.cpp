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

bool compareX(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

// Cross product to check turn direction
int crossProduct(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    return (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
}

// Function to merge two convex hulls into a single convex hull
vector<pair<int, int>> mergeHulls(const vector<pair<int, int>> &left, const vector<pair<int, int>> &right) {
    vector<pair<int, int>> merged = left;
    merged.insert(merged.end(), right.begin(), right.end());

    // Sort the merged points to construct the convex hull correctly
    sort(merged.begin(), merged.end(), compareX);

    vector<pair<int, int>> hull;

    // **Lower hull**
    for (auto &p : merged) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // **Upper hull**
    int lowerSize = hull.size();
    for (int i = merged.size() - 2; i >= 0; i--) {
        while (hull.size() > lowerSize && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], merged[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(merged[i]);
    }

    // Remove the last point because it is duplicated at the start
    hull.pop_back();

    return hull;
}

// Divide and conquer function
vector<pair<int, int>> divideAndConquer(vector<pair<int, int>> &points) {
    int n = points.size();
    if (n <= 3) {
        sort(points.begin(), points.end(), compareX);
        return points;  // Base case: 3 or fewer points already form a convex shape
    }

    int mid = n / 2;
    vector<pair<int, int>> left(points.begin(), points.begin() + mid);
    vector<pair<int, int>> right(points.begin() + mid, points.end());

    vector<pair<int, int>> leftHull = divideAndConquer(left);
    vector<pair<int, int>> rightHull = divideAndConquer(right);

    return mergeHulls(leftHull, rightHull);
}

// Main function to compute the convex hull
vector<pair<int, int>> computeConvexHull(vector<pair<int, int>> &points) {
    sort(points.begin(), points.end(), compareX);
    return divideAndConquer(points);
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
    ans = computeConvexHull(graph);
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
        ans = computeConvexHull(graph_copy);
        end3 = high_resolution_clock::now();
        dc_time = duration<long long, nano>(end3 - start1).count();

        file << numPoints << " " << graham_time << " " << brute_time << " " << dc_time << "\n";
    }

    // Close the file
    file.close();    
    return 0;
}