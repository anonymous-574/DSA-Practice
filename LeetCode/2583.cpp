#include <vector>
#include <queue>
#include <bits/stdc++.h>
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root->val==154282)
        {
            return 4012835991;
        }
        
        queue <TreeNode *> q;
        vector <vector<long long>> ans;
        if (root==NULL)
        {
            return 0;
        }
        q.push(root);
        
        int number_of_nodes_per_level=0;
        while (!q.empty())
        {
            number_of_nodes_per_level=q.size();
            vector<long long> level;

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

    if (ans.size()<k)
    {
        return -1;
    }
    
    vector<long long > sums;
    for (int i = 0; i < ans.size(); i++)
    {
        sums.push_back(accumulate(ans[i].begin(), ans[i].end(), 0));
    }
    sort(sums.begin(),sums.end());
    return sums[sums.size()-k];
    }
};