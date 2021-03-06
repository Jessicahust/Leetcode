#include<iostream>
#include<new>
#include<vector>
using namespace std;


// Definition for binary tree with next pointer.
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if(root==NULL)
            return;
        vector<TreeLinkNode*> q;
        vector<TreeLinkNode*> curq;
        q.push_back(root);
        TreeLinkNode *tmp;
        while(!q.empty())
        {
            curq=q;
            q.clear();
            for(size_t i=0;i<curq.size();i++)
            {
                tmp=curq[i];
                if(i<curq.size()-1)
                    tmp->next=curq[i+1];
                else
                    tmp->next=NULL;
                if(tmp->left)
                    q.push_back(tmp->left);
                if(tmp->right)
                    q.push_back(tmp->right);
            }
        }
    }
    void createTree(TreeLinkNode *&root)
    {
        int i;
        cin>>i;
        if(i!=0)
        {
            root=new TreeLinkNode(i);
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
    TreeLinkNode *root;
    s.createTree(root);
    s.connect(root);
}
