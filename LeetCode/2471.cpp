#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

    int get_swaps(vector<int> arr)
    {
        int ans=0;
        unordered_map<int,int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp.insert(make_pair(arr[i],i));
        }
        vector <int> v2=arr;
        sort(v2.begin(),v2.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (mp[arr[i]]!=i)
            {
                ans++;
                swap(arr[i],arr[mp[arr[i]]]);
            }
            
        }
        
        

    return ans;
    }

    int minimumOperations(TreeNode* root) {
        
        queue <TreeNode *>q;
        q.push(root);
        int level_no=0;
        vector <vector<int>> levels;
        
        int number_of_nodes_per_level=0;
        while (!q.empty())
        {
            number_of_nodes_per_level=q.size();
            vector <int> curr_level;

            for (int i = 0; i < number_of_nodes_per_level; i++)
            {
            TreeNode * curr = q.front();
            curr_level.push_back(curr->val);
            q.pop();

            if (curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if (curr->right!=NULL)
            {
                q.push(curr->right);
            }
            }
            
            levels.push_back(curr_level);

            
        level_no++;
        }
        int ans=0;
        for (int i = 0; i < levels.size(); i++)
        {
            ans+=get_swaps(levels[i]);
        }
        

    return ans;
    }
};