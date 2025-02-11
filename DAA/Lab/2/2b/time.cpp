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

double angle(pair<int, int> p, pair<int, int> p0) {
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
        double angleA = angle(a, p0);
        double angleB = angle(b, p0);
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

int main(int argc, char const *argv[])
{
    ofstream file("time.txt");

    // Initial set of 4 random points
    srand(time(NULL));
    vector<pair<int, int>> graph;
    for (int i = 0; i < 4; ++i) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));
    }

    // Measure the time for the first iteration (4 points)
    auto start1 = high_resolution_clock::now();
    vector<pair<int, int>> ans = graham(graph);
    auto end1 = high_resolution_clock::now();
    double insertionTime = duration<double, nano>(end1 - start1).count();
    file << 4 << " " << insertionTime << "\n";

    // Iterate from 5 points to 100 points
    for (int numPoints = 5; numPoints <= 100; ++numPoints) {
        // Add one new random point to the existing set
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));

        // Measure the time taken for the Graham scan with the new set of points
        auto start1 = high_resolution_clock::now();
        vector<pair<int, int>> ans = graham(graph);
        auto end1 = high_resolution_clock::now();
        insertionTime = duration<double, nano>(end1 - start1).count(); // Time in nanoseconds

        // Save the result (number of points and time) to the file
        file << numPoints << " " << insertionTime << "\n";
    }

    // Close the file
    file.close();

    cout << "Times saved to time.txt" << endl;
    return 0;
}
