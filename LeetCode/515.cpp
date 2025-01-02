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
    vector<int> largestValues(TreeNode* root) {
        vector <int> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        vector<int> level;
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int no_of_nodes_per_level=q.size();

            for (int i = 0; i < no_of_nodes_per_level; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left!=NULL){
                    q.push(curr->left);
                }
                if (curr->right!=NULL){
                    q.push(curr->right);
                }
                level.push_back(curr->val);
            }
            
            ans.push_back(*max_element(level.begin(),level.end()));
            level.clear();

        }
    return ans;
    }
};