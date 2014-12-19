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

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        if(p->val==q->val&&p->left==NULL&&q->left==NULL&&p->right==NULL&&q->right==NULL)
            return true;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
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
    TreeNode *root1=NULL;
    TreeNode *root2=NULL;
    s.createTree(root1);
    s.createTree(root2);
    cout<<s.isSameTree(root1,root2)<<endl;
}
