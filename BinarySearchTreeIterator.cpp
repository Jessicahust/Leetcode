#include<iostream>
#include<new>
#include<stack>
using namespace std;

/**
 * Definition for binary tree
  */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmp=NULL;
        if(!st.empty())
        {
            tmp=st.top();
            st.pop();
            TreeNode *cur=tmp->right;
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
        }
        return tmp->val;
    }
};

void insert(TreeNode *&root,int val)
{
    if(root==NULL)
    {
        root=new TreeNode(val);
    }
    else if(val<root->val)
        insert(root->left,val);
    else
        insert(root->right,val);
}

void createBST(TreeNode *&root)
{
    int i;
    int arr[10]= {2,4,6,1,3,5,9,8,7,10};
    for(i=0; i<10; i++)
    {
        insert(root,arr[i]);
    }
}

int main()
{
    TreeNode *root=NULL;
    createBST(root);
    BSTIterator s(root);
    for(int i=0;i<10;i++)
        cout<<s.next()<<" ";
    cout<<endl;
}
