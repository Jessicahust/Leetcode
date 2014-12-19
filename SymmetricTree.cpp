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
    bool isSymmetric(TreeNode *root)
    {
        if(root==NULL)
            return true;
        return isSubtree(root->left,root->right);
    }
    bool isSubtree(TreeNode *root1,TreeNode *root2)
    {
        if(root1==NULL||root2==NULL)
            return (root1==NULL)&&(root2==NULL);
        return (root1->val==root2->val)&&isSubtree(root1->left,root2->right)&&isSubtree(root1->right,root2->left);
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
    cout<<s.isSymmetric(root)<<endl;
}


