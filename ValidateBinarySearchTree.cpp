#include<iostream>
#include<new>
#include<vector>
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
    bool isValidBST(TreeNode *root)
    {
        if(root==NULL)
            return true;
        vector<int> rvec;
        preorder(root,rvec);
        size_t i;
        int max;
        if(rvec.size())
            max=rvec[0];
        for(i=1;i<rvec.size();i++)
        {
            if(rvec[i]>max)
            {
                max=rvec[i];
            }
            else
                return false;
        }
        return true;
    }
    void preorder(TreeNode *root,vector<int> &rvec)
    {
        if(root)
        {
            preorder(root->left,rvec);
            rvec.push_back(root->val);
            preorder(root->right,rvec);
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
    cout<<s.isValidBST(root)<<endl;
}

