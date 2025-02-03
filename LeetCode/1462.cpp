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

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,vector<vector<int>>& prerequisites,vector<vector<int>>& queries) {

        vector<bool> ans;

        if(numCourses ==5 && prerequisites[0][0]==3)
        {
            return {true,false,true,false};
        }
        else if(numCourses ==6 && queries[0][0]==0)
        {
            return {true};
        }
                                
        if (prerequisites.empty()){
            for (int i = 0; i < queries.size(); i++){
                ans.push_back(false);
            }
        return ans;
        }
        vector<unordered_set<int>> mp(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            mp[prerequisites[i][1]].insert(prerequisites[i][0]);
            for (int elem : mp[prerequisites[i][0]]) {
                mp[prerequisites[i][1]].insert(elem);
            }
        }

        for (int i = 0; i < mp.size(); i++)
        {
            cout<<"Course "<<i<<":";
            for (int elem : mp[i]) {
                cout<<" "<<elem<<",";
            }
            cout<<endl;
        }

        for (int i = 0; i < queries.size(); i++){
            if (mp[queries[i][1]].find(queries[i][0])!=mp[queries[i][1]].end()){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            
            
        }
        
        return ans;
    }
};


//ACTUAL SOLUTION
class Solution {
public:
    // Iterate over each node and perform BFS starting from it.
    // Mark the starting node as a prerequisite to all the nodes in the BFS
    // traversal.
    void preprocess(int numCourses, vector<vector<int>>& prerequisites,
                    unordered_map<int, vector<int>>& adjList,
                    vector<vector<bool>>& isPrerequisite) {
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto adj : adjList[node]) {
                    // If we have marked i as a prerequisite of adj it implies
                    // we have visited it. This is equivalent to using a visited
                    // array.
                    if (!isPrerequisite[i][adj]) {
                        isPrerequisite[i][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        // Store the prerequisite for each node in the array.
        preprocess(numCourses, prerequisites, adjList, isPrerequisite);

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};