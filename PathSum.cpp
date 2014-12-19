#include<iostream>
#include<new>
#include<vector>
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if(root->left==NULL&&root->right==NULL&&(sum-root->val)==0)
            return true;
        if(root->left)
            return hasPathSum(root->left,sum-root->val);
        if(root->right)
            return hasPathSum(root->right,sum-root->val);
        return false;
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
    if(s.hasPathSum(root,6))
        cout<<"exist"<<endl;
}
