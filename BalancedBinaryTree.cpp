#include<iostream>
#include<new>
#include<vector>
#include<cmath>
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
    bool isBalanced(TreeNode *root)
    {
        if(root==NULL)
            return true;
        int lhigh=maxDepth(root->left);
        int rhigh=maxDepth(root->right);
        if(abs(lhigh-rhigh)>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int maxDepth(TreeNode *root)
    {
        if(root)
        {
            if(root->left==NULL&&root->right==NULL)
                return 1;
            int leftDepth=maxDepth(root->left);
            int rightDepth=maxDepth(root->right);
            return leftDepth>= rightDepth ?(leftDepth+1):(rightDepth+1);
        }
        return 0;
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
    cout<<s.maxDepth(root);
    cout<<endl;
    cout<<s.isBalanced(root)<<endl;
}
