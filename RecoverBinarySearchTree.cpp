#include<iostream>
#include<new>
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
    TreeNode *first=NULL;
    TreeNode *second=NULL;
    TreeNode *pre=NULL;
    void recoverTree(TreeNode *root)
    {
        recoverInorder(root);
        swap(first->val,second->val);
    }
    void recoverInorder(TreeNode *root)
    {
        if(root)
        {
            recoverInorder(root->left);
            if(pre&&pre->val>root->val)
            {
                if(first==NULL)
                {
                    first=pre;
                    second=root;
                }
                else
                    second=root;
            }
            pre=root;
            recoverInorder(root->right);
        }
    }
    void createTree(TreeNode *&root)
    {
        int arr[10]= {5,9,7,8,6,10,4,2,1,3};
        int i;
        for(i=0; i<10; i++)
            insert(root,arr[i]);
    }
    void insert(TreeNode *&root,int key)
    {
        TreeNode *tmp=new TreeNode(key);
        if(root==NULL)
        {
            root=tmp;
        }
        else if(key<root->val)
            insert(root->left,key);
        else
            insert(root->right,key);
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
    s.createTree(root);
    s.inorder(root);
    cout<<endl;
    swap(root->left->val,root->right->val);
    s.inorder(root);
    cout<<endl;
    s.recoverTree(root);
    s.inorder(root);
}
