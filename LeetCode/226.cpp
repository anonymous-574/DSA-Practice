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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        {
            return root;
        }
        queue <TreeNode *> q;
        q.push(root);
        TreeNode * temp=NULL;
        int number_of_nodes_per_level=0;
        while (!q.empty())
        {
            number_of_nodes_per_level=q.size();

            for (int i = 0; i < number_of_nodes_per_level; i++)
            {
                TreeNode * node = q.front();
                q.pop();

                
                if (node->left!=NULL && node->right!=NULL)
                {

                    q.push(node->left);
                    q.push(node->right);
                    temp=node->left;
                    node->left=node->right;
                    node->right=temp;
                    
                }
                else if (node->left==NULL && node->right!=NULL)
                {
                    q.push(node->right);
                    node->left=node->right;
                    node->right=NULL;
                }
                else if (node->left!=NULL && node->right==NULL)
                {
                    q.push(node->left);
                    node->right=node->left;
                    node->left=NULL;  
                }
                
            
            }
        }
    return root;

    }
};

/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};


*/