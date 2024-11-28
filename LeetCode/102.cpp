#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode *> q;
        vector <vector<int>> ans;
        if (root==NULL)
        {
            return ans;
        }
        q.push(root);
        
        int number_of_nodes_per_level=0;
        while (!q.empty())
        {
            number_of_nodes_per_level=q.size();
            vector<int> level;

            for (int i = 0; i < number_of_nodes_per_level; i++)
            {
                TreeNode * node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left!=NULL)
                {
                    q.push(node->left);
                }
                if (node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
    return ans;
    }
};