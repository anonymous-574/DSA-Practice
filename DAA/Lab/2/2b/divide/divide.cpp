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

int main() {
    vector<pair<int, int>> graph;
    srand(time(NULL));

    for (int i = 0; i < 100; ++i) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));
    }

    
    sort(graph.begin(),graph.end());
    vector<pair<int, int>> ans = computeConvexHull(graph);

    ofstream file("points.txt");

    file << "Graph Points:\n";
    for (int i = 0; i < graph.size(); i++) {
        file << graph[i].first << " " << graph[i].second << "\n";
    }

    file << "\nConvex Hull Points (Answer):\n";
    for (int i = 0; i < ans.size(); i++) {
        file << ans[i].first << " " << ans[i].second << "\n";
    }

    file.close();
    return 0;
}