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
    vector<pair<int, int>> graph;
    srand(time(NULL));

    for (int i = 0; i < 100; ++i) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        graph.push_back(make_pair(x, y));
    }

    

    vector<pair<pair<int,int>,pair<int,int>>> ans = brute(graph);

    ofstream file("points.txt");

    if (!file) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    file << "Graph Points:\n";
    for (const auto& p : graph) {
        file << p.first << " " << p.second << "\n";
    }

    file << "\nConvex Hull Edges:\n";
    for (const auto& edge : ans) {
        file << edge.first.first << " " << edge.first.second << " "
             << edge.second.first << " " << edge.second.second << "\n";
    }

    file.close();
    return 0;
}