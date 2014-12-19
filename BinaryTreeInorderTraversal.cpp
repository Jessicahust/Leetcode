#include<iostream>
#include<new>
#include<vector>
#include<stack>
using namespace std;

//Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if(root==NULL)
            return vector<int>();
        stack<TreeNode*> s;
        vector<int> vec;
        while(root||!s.empty())
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                vec.push_back(root->val);
                s.pop();
                root=root->right;
            }
        }
        return vec;
    }
    void createTree(TreeNode *&root)
    {
        int i;
        cin>>i;
        if(i!=0)
        {
            root=new TreeNode(i);
            if(root==NULL)
                return;
            createTree(root->left);
            createTree(root->right);
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root;
    s.createTree(root);
    vector<int> vec;
    vec=s.inorderTraversal(root);
    for(auto a:vec)
        cout<<a<<" ";
    cout<<endl;
}
