#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <limits>
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


class FindElements {
    public:

        unordered_set<int>hold;
        FindElements(TreeNode* root) {
            root->val=0;
            hold.insert(0);
            queue<TreeNode*>q;
            q.push(root);
            TreeNode * curr;
            while (!q.empty()){
                curr=q.front();
                q.pop();
                int no=(2*curr->val);
                if (curr->left!=NULL){
                    q.push(curr->left);
                    curr->left->val=no+1;
                    hold.insert(no+1);
                }
                if (curr->right!=NULL){
                    q.push(curr->right);
                    curr->right->val=(2*curr->val) +2;
                    hold.insert(no+2);
                }
                
            }
            

        }
        
        bool find(int target) {
            if (hold.find(target)==hold.end()){
                return false;
            }
        return true;
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */