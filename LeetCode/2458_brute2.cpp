#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <unordered_map>
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
    unordered_map<int,int> mp;
    stack <TreeNode*> st;
    TreeNode * node=NULL;
    TreeNode * temp=NULL;

    st.push(root);
    while (!st.empty())
    {
        node=st.top();
        st.pop();
        if (node->left!=NULL && node->right!=NULL)
        {             
            st.push(node->left);
            temp=node->left;
            node->left=NULL;
            mp.insert({temp->val,calc_height(root)-1});
            node->left=temp;

            st.push(node->right);
            temp=node->right;
            node->right=NULL;
            mp.insert({temp->val,calc_height(root)-1});
            node->right=temp;
        }
        else if (node->left!=NULL && node->right==NULL)
        {
            st.push(node->left);
            temp=node->left;
            node->left=NULL;
            mp.insert({temp->val,calc_height(root)-1});
            node->left=temp;
        }
        else if (node->left==NULL && node->right!=NULL)
        {
            st.push(node->right);
            temp=node->right;
            node->right=NULL;
            mp.insert({temp->val,calc_height(root)-1});
            node->right=temp;
        }
    }
    
    for (int i = 0; i < queries.size(); i++)
    {
        ans.push_back(mp[queries[i]]);
    }
    


    return ans;
    }
};