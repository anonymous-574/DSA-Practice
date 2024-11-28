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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue <TreeNode *> q;
        vector <vector<int>> arr_of_all_nodes_levelwise;
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
            arr_of_all_nodes_levelwise.push_back(level);
        }

        vector<long long > sums;
        //sums is simply an array of sums of each level
        for (int i = 0; i < arr_of_all_nodes_levelwise.size(); i++)
        {
        sums.push_back(accumulate(arr_of_all_nodes_levelwise[i].begin(), arr_of_all_nodes_levelwise[i].end(), 0));
        }

        queue <TreeNode *> q1;
        q1.push(root);

        int level1=0;
        number_of_nodes_per_level=0;
        while (!q1.empty())
        {
            number_of_nodes_per_level=q1.size();
            level1++;
            for (int i = 0; i < number_of_nodes_per_level; i++)
            {
                TreeNode * node = q1.front();
                q1.pop();
                
                if (node->left!=NULL && node->right!=NULL)
                {
                    q1.push(node->left);
                    q1.push(node->right);
                    int temp =  node->left->val;
                    node->left->val=sums[level1]-(temp+node->right->val);
                    node->right->val=sums[level1]-(temp+node->right->val);
                }
                else if (node->left==NULL && node->right!=NULL)
                {
                    q1.push(node->right);
                    node->right->val=sums[level1]-node->right->val;
                }
                else if (node->left!=NULL && node->right==NULL)
                {
                    q1.push(node->left);
                    node->left->val=sums[level1]-node->left->val;
                }
            }
        }
    
    root->val=0;
    return root;
    }
};