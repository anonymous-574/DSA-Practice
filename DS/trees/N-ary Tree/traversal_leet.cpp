#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val;
    vector<node*> children;
};

vector<int> arr;
vector<int> postorder(node* root) {
        if(root==NULL)
        {
            return {};
        }
            for(int i=0 ; i<root->children.size(); i++)
            {
                postorder(root->children[i]);
            }
            arr.push_back(root->val);
        
        return arr;
    }

vector<int> preorder(node* root) {
        if(root==NULL)
        {
            return {};
        }
            arr.push_back(root->val);
            for(int i=0 ; i<root->children.size(); i++)
            {
                preorder(root->children[i]);
            }
            
        
        return arr;
    }

vector<int> preorder(node* root) {
        if(root==NULL)
        {
            return {};
        }
            arr.push_back(root->val);
            for(int i=0 ; i<root->children.size(); i++)
            {
                preorder(root->children[i]);
            }
            
        
        return arr;
    }

int main(int argc, char const *argv[])
{
    
    return 0;
}
