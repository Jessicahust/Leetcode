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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > vec;
        vector<vector<TreeNode*> > rvec;
        size_t i=0;
        if(root==NULL)
            return vector<vector<int> >();
        vec.push_back({root->val});
        rvec.push_back({root});
        vector<int> v1;
        vector<TreeNode*> v2;
        while(vec.size()&&rvec.size())
        {
            v1.clear();
            v2.clear();
            for(i=0; i<rvec[rvec.size()-1].size(); i++)
            {
                cout<<"level : "<<vec.size()<<"val: "<<vec[rvec.size()-1][i]<<endl;
                TreeNode *tmp=rvec[rvec.size()-1][i];
                cout<<"level : "<<vec.size()<<"node: "<<tmp->val<<endl;
                if(tmp->left)
                {
                    v1.push_back(tmp->left->val);
                    v2.push_back(tmp->left);
                }
                if(tmp->right)
                {
                    v1.push_back(tmp->right->val);
                    v2.push_back(tmp->right);
                }
            }
            if(!v1.empty()&&!v2.empty())
            {
                vec.push_back(v1);
                rvec.push_back(v2);
            }
            else
                break;
        }
        return vec;
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
    vector<vector<int> > vec=s.levelOrder(root);
    for(auto a:vec)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
