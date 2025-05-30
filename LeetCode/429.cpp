#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        if(root==NULL){return ans;}
        vector<int> temp;
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int nodes_level=q.size();

            for (int i = 0; i < nodes_level; i++)
            {
                Node* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                for (int j = 0; j < curr->children.size(); j++)
                {
                    q.push(curr->children[j]);
                }
                
            }
            ans.push_back(temp);
            temp.clear();
        }
    return ans;
    }
};