#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
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

    int calc_height(TreeNode* root)
    {
    if (root == NULL)
    return 0;

    int left= calc_height(root->left);
    int right= calc_height(root->right);

    return max(left, right)+1;
    }


    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    vector<int> ans;
    stack <TreeNode*> st;
    TreeNode * node=NULL;
    TreeNode * temp=NULL;

    for (int i = 0; i < queries.size(); i++)
    { 
        st.push(root);
    while (!st.empty())
    {
        node=st.top();
        st.pop();
        if (node->left!=NULL && node->right!=NULL)
        {
            if (node->left->val==queries[i] )
            {
                temp=node->left;
                node->left=NULL;
                ans.push_back(calc_height(root)-1);
                node->left=temp;
                continue;
            }
            else if (node->right->val==queries[i])
            {
                temp=node->right;
                node->right=NULL;
                ans.push_back(calc_height(root)-1);
                node->right=temp;
                continue;
            }
            
            
            st.push(node->left);
            st.push(node->right);
        }
        else if (node->left!=NULL && node->right==NULL)
        {
            if (node->left->val==queries[i] )
            {
                temp=node->left;
                node->left=NULL;
                ans.push_back(calc_height(root)-1);
                node->left=temp;
                continue;
            }
            st.push(node->left);
        }
        else if (node->left==NULL && node->right!=NULL)
        {
            if (node->right->val==queries[i] )
            {
                temp=node->right;
                node->right=NULL;
                ans.push_back(calc_height(root)-1);
                node->right=temp;
                continue;
            }
            st.push(node->right);
        }
   
    }

    }
    

    return ans;
    }
};