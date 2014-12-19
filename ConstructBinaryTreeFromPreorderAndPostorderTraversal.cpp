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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root=NULL;
        root=build(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
        return root;
    }
    TreeNode *build(vector<int>::iterator ibegin,vector<int>::iterator iend,vector<int>::iterator pbegin,vector<int>::iterator pend)
    {
        TreeNode *root=NULL;
        if(pbegin==pend||ibegin==iend)
            return NULL;
        auto it=ibegin;
        auto tmp=pend-1;
        while(it!=iend)
        {
            if(*it==*tmp)
                break;
            it++;
        }
        root=new TreeNode(*it);
        int len=it-ibegin;
        root->left=build(ibegin,it,pbegin,pbegin+len);
        root->right=build(it+1,iend,pbegin+len,pend-1);
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
    vector<int> posorder={4,5,2,6,7,3,1};
    vector<int> inorder={4,2,5,1,6,3,7};
    Solution s;
    TreeNode *root=s.buildTree(inorder,posorder);
    s.preorder(root);
    cout<<endl;
    s.inorder(root);
    cout<<endl;
    s.postorder(root);
    cout<<endl;
}


