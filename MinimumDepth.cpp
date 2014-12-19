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
    int minDepth(TreeNode *root)
    {
        if(root)
        {
            if(root->left==NULL&&root->right==NULL)
                return 1;
            int lmin=minDepth(root->left);
            int rmin=minDepth(root->right);
            if(root->left&&root->right==NULL)
                return lmin+1;
            if(root->left==NULL&&root->right)
                return rmin+1;
            return (lmin<= rmin)?(lmin+1):(rmin+1);
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
    cout<<s.minDepth(root)<<endl;
}

