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

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root=NULL;
        root=build(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
        return root;
    }
    TreeNode *build(vector<int>::iterator pbegin,vector<int>::iterator pend,vector<int>::iterator ibegin,vector<int>::iterator iend)
    {
        TreeNode *root=NULL;
        if(pbegin==pend||ibegin==iend)
            return NULL;
        auto it=ibegin;
        while(it!=iend)
        {
            if(*it==*pbegin)
                break;
            it++;
        }
        root=new TreeNode(*pbegin);
        int len=it-ibegin;
        root->left=build(pbegin+1,pbegin+1+len,ibegin,it);
        root->right=build(pbegin+1+len,pend,it+1,iend);
        return root;
    }
    void preorder(TreeNode *root)
    {
        if(root)
        {
            cout<<root->val<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(TreeNode *root)
    {
        if(root)
        {
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
        }
    }
    void postorder(TreeNode *root)
    {
        if(root)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->val<<" ";
        }
    }
};

int main()
{
    vector<int> preorder={1,2,4,5,3,6,7};
    vector<int> inorder={4,2,5,1,6,3,7};
    Solution s;
    TreeNode *root=s.buildTree(preorder,inorder);
    s.preorder(root);
    cout<<endl;
    s.inorder(root);
    cout<<endl;
    s.postorder(root);
    cout<<endl;
}

