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
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector<vector<int> > path;
        vector<int> tmp;
        hasPathSum(root,sum,path,tmp);
        return path;
    }
    void hasPathSum(TreeNode *root, int sum,vector<vector<int> > &path,vector<int> tmp)
    {
        if(root==NULL)
            return;
        tmp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&(sum-root->val)==0)
        {
            path.push_back(tmp);
        }
        if(root->left)
            hasPathSum(root->left,sum-root->val,path,tmp);
        if(root->right)
            hasPathSum(root->right,sum-root->val,path,tmp);
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
    vector<vector<int> > path=s.pathSum(root,6);
    for(auto a:path)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}

