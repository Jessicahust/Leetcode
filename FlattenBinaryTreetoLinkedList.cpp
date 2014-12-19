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
    void flatten(TreeNode *root)
    {
        if(root==NULL)
            return;
        vector<TreeNode*> vec;
        preorder(root,vec);
        TreeNode *tmp=root;
        size_t i;
        for(i=1; i<vec.size(); i++)
        {
            //一定要记得将左指针置为NULL
            tmp->left=NULL;
            tmp->right=vec[i];
            tmp=tmp->right;
        }
        tmp->left=tmp->right=NULL;
    }
    void preorder(TreeNode *root,vector<TreeNode*> &vec)
    {
        stack<TreeNode*> s;
        while(root||!s.empty())
        {
            while(root)
            {
                vec.push_back(root);
                s.push(root);
                root=root->left;
            }
            if(!s.empty())
            {
                root=s.top();
                s.pop();
                root=root->right;
            }
        }
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
    s.flatten(root);
    while(root)
    {
        cout<<root->val<<" ";
        root=root->right;
    }
}


