#include<iostream>
#include<new>
#include<climits>
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
    int maxPathSum(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
    int helper(TreeNode *root,int &res)
    {
        if(root==NULL)
            return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        int val=root->val;
        if(left>0)
            val+=left;
        if(right>0)
            val+=right;
        int ret=max(root->val,root->val+max(left,right));
        //res指的是所有root中的所有路径的最大值，不一定以root为根，因此不能返回给上层
        res=max(res,max(val,ret));
        //返回值表示的是以root为根的最大值
        return ret;
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
    cout<<s.maxPathSum(root)<<endl;
}

