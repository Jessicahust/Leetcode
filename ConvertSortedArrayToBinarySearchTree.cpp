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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        if(num.empty())
            return NULL;
        TreeNode *root=NULL;
        int i;
        for(i=0; i<(int)num.size(); i++)
            insert(root,num[i]);
        return root;
    }
    void insert(TreeNode *&root,int key)
    {
        int lhigh,rhigh;
        if(root==NULL)
        {
            root=new TreeNode(key);
            if(root==NULL)
                return;
        }
        else if(key<root->val)
        {
            insert(root->left,key);
            lhigh=maxDepth(root->left);
            rhigh=maxDepth(root->right);
            if(abs(lhigh-rhigh)>1)
            {
                if(key<root->left->val)
                    root=SingleRotateWithLeft(root);
                else
                    root=DoubleRotateWithLeft(root);
            }
        }
        else
        {
            insert(root->right,key);
            lhigh=maxDepth(root->left);
            rhigh=maxDepth(root->right);
            if(abs(lhigh-rhigh)>1)
            {
                if(key>root->right->val)
                    root=SingleRotateWithRight(root);
                else
                    root=DoubleRotateWithLeft(root);
            }
        }
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
    TreeNode* SingleRotateWithLeft(TreeNode *&root)
    {
        TreeNode *l=root->left;
        root->left=l->right;
        l->right=root;
        return l;
    }
    TreeNode* SingleRotateWithRight(TreeNode *&root)
    {
        TreeNode *r=root->right;
        root->right=r->left;
        r->left=root;
        return r;
    }
    TreeNode* DoubleRotateWithLeft(TreeNode *&root)
    {
        SingleRotateWithRight(root->left);
        return SingleRotateWithLeft(root);
    }
    TreeNode* DoubleRotateWithRight(TreeNode *&root)
    {
        SingleRotateWithLeft(root->right);
        return SingleRotateWithRight(root);
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
};

int main()
{
    Solution s;
    TreeNode *root=NULL;
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    root=s.sortedArrayToBST(vec);
    s.inorder(root);
    cout<<endl;
    cout<<s.maxDepth(root)<<endl;
}
