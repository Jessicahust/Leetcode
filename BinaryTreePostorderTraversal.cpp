#include<iostream>
#include<new>
#include<vector>
#include<stack>
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode*> st;
        vector<int> ret;
        if(root==NULL)
            return vector<int>();
        st.push(root);
        TreeNode *pre=NULL;
        TreeNode *cur;
        while(!st.empty())
        {
            cur=st.top();
            if((cur->left==NULL&&cur->right==NULL)||((pre!=NULL)&&(pre==cur->left||pre==cur->right)))
            {
                ret.push_back(cur->val);
                st.pop();
                pre=cur;
            }
            else
            {
                if(cur->right)
                    st.push(cur->right);
                if(cur->left)
                    st.push(cur->left);
            }
        }
        return ret;
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
    vector<int> vec;
    vec=s.postorderTraversal(root);
    for(auto a:vec)
        cout<<a<<" ";
    cout<<endl;
}

