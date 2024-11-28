#include <vector> 
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
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

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if (root1==NULL && root2==NULL)
        {
            return true;
        }

        if (root1==NULL || root2==NULL)
        {
            return false;
        }
        
        if (root1->val!=root2->val)
        {
            return false;
        }
        

        queue <TreeNode *> q;
        q.push(root1);
        queue <TreeNode *> q1;
        q1.push(root2);
        int number_of_nodes_per_level1=0;
        int number_of_nodes_per_level2=0;
        TreeNode * temp=NULL;
        while (!q.empty() && !q1.empty())
        {
            number_of_nodes_per_level1=q.size();
            number_of_nodes_per_level2=q1.size();
            if (number_of_nodes_per_level1!=number_of_nodes_per_level2)
            {
                return false;
            }
                TreeNode * node1 = q.front();
                q.pop();
                TreeNode * node2 = q1.front();
                q1.pop();
                if (node1->val!=node2->val)
                {
                    return false;
                }     
            
            int left1=0;
            int left2=0;
            int right1=0;
            int right2=0;

            if (node1->left!=NULL)
            {
                left1=node1->left->val;
            }
            else
            {
                left1=-1;
            }
            
            if (node1->right!=NULL)
            {
                right1=node1->right->val;
            }
            else
            {
                right1=-1;
            }
            
            if (node2->left!=NULL)
            {
                left2=node2->left->val;
            }
            else
            {
                left2=-1;
            }
            
            if (node2->right!=NULL)
            {
                right2=node2->right->val;
            }
            else
            {
                right2=-1;
            }
            

            if (left1 == right2 && right1 == left2)
            {
                temp=node1->left;
                node1->left=node1->right;
                node1->right=temp;
            }
            

            if (node1->left!=NULL)
            {
                q.push(node1->left);
            }
            if (node1->right!=NULL)
            {
                q.push(node1->right);
            }
            if (node2->left!=NULL)
            {
                q1.push(node2->left);
            }
            if (node2->right!=NULL)
            {
                q1.push(node2->right);
            }
            
        }

    
    
    return true;
    }
};