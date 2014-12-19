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
    vector<TreeNode *> generateTrees(int n)
    {
        return generate(1,n);
    }
    vector<TreeNode *> generate(int start,int end)
    {
        vector<TreeNode *> ret;
        if(start>end)
        {
            ret.push_back(NULL);
            return ret;
        }
        if(start==end)
        {
            TreeNode *root=new TreeNode(start);
            ret.push_back(root);
            return ret;
        }
        int i=start;
        for(i=start;i<=end;i++)
        {
            vector<TreeNode *> leftTree=generate(start,i-1);
            vector<TreeNode *> rightTree=generate(i+1,end);
            for(size_t j=0;j<leftTree.size();j++)
            {
                for(size_t k=0;k<rightTree.size();k++)
                {
                    TreeNode *root=new TreeNode(i);
                    root->left=leftTree[j];
                    root->right=rightTree[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> vec=s.generateTrees(3);
    for(auto a:vec)
        cout<<a->val<<" ";
    cout<<endl;
}
