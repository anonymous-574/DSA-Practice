#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

//FAIL
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<bool> visited(edges.size(),false);

        vector<int> ans;
        for (int i = 0; i < edges.size(); i++){
            if (!visited[edges[i][0]] || !visited[edges[i][1]]){
                visited[edges[i][0]]=true;
                visited[edges[i][1]]=true;
            }
            else if (visited[edges[i][0]] && visited[edges[i][1]]){
                ans.clear();
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
        }
        

    return ans;
    }
};

class Solution {
private:
    // Performs DFS and returns true if there's a path between src and target.
    bool isConnected(int src, int target, vector<bool>& visited,
                     vector<int> adjList[]) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        int isFound = false;
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }

        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> adjList[N];
        for (auto edge : edges) {
            vector<bool> visited(N, false);

            // If DFS returns true, we will return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
};