#include<iostream>
#include<new>
#include<vector>
#include<sstream>
#include<cstdlib>
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
    int sumNumbers(TreeNode *root) {
        vector<int> vec;
        vector<int> tmp;
        int sum=0;
        hasPathSum(root,vec,tmp);
        for(auto a:vec)
           sum+=a;
        return sum;
    }
//path传入引用是因为，每一个对path的操作都要有影响，而tmp作为参数传入，是因为将上层的修改带入下层，但是下层对tmp的修改不会影响上层的操作
    void hasPathSum(TreeNode *root,vector<int> &path,vector<int> tmp)
    {
        if(root==NULL)
            return;
        tmp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            stringstream ss;
            for(size_t i=0;i<tmp.size();i++)
                ss<<tmp[i];
            string s=ss.str();
            int c=atoi(s.c_str());
            path.push_back(c);
        }
        if(root->left)
            hasPathSum(root->left,path,tmp);
        if(root->right)
            hasPathSum(root->right,path,tmp);
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
    int sum=s.sumNumbers(root);
    cout<<sum<<endl;
}


