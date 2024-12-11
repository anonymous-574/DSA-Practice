#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void helper(struct TreeNode* root, int val,struct TreeNode* n)
{

    struct TreeNode* prev=NULL;
    
    while (root!=NULL)
    {
        prev=root;
        if (root->val > val)
        {
            root=root->left;
        }
        else
        {  
            root=root->right;
        }  
    }
    
    if (prev->val>val)
    {
        prev->left=n;
    }
    else
    {
        prev->right=n;
    }
    
    
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* n = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    n->val=val;
    n->left = NULL;
    n->right = NULL;

    if (root==NULL)
    {
        root=n;
        return root;
    }

    struct TreeNode* oroot=root;
    helper(root,val,n);
    return oroot;
}