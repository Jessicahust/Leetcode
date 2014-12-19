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
        if(preorder.empty()||inorder.empty())
            return NULL;
        TreeNode *root=new TreeNode(preorder[0]);
        int i;
        for(i=0;i<(int)inorder.size();i++)
        {
            if(preorder[0]==inorder[i])
                break;
        }
        if(i>=(int)inorder.size())
            return NULL;
        vector<int> ileft(inorder.begin(),inorder.begin()+i);
        vector<int> iright(inorder.begin()+i+1,inorder.end());
        vector<int> pleft(preorder.begin()+1,preorder.begin()+1+i);
        vector<int> pright(preorder.begin()+1+i,preorder.end());
        root->left=buildTree(pleft,ileft);
        root->right=buildTree(pright,iright);
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
