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

int main() {
    vector<pair<int, int>> graph;
    srand(time(NULL));

    for (int i = 0; i < 100; ++i) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));
    }

    

    vector<pair<int, int>> ans = graham(graph);

    ofstream file("points.txt");

    // Save graph points
    file << "Graph Points:\n";
    for (int i = 0; i < graph.size(); i++) {
        file << graph[i].first << " " << graph[i].second << "\n";
    }

    // Save ans points
    file << "\nConvex Hull Points (Answer):\n";
    for (int i = 0; i < ans.size(); i++) {
        file << ans[i].first << " " << ans[i].second << "\n";
    }

    file.close();

    cout << "Points saved to points.txt" << endl;
    return 0;
}