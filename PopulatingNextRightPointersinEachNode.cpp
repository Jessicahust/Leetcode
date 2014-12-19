#include<iostream>
#include<new>
#include<queue>
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
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode *tmp=root;
        while(!q.empty())
        {
            tmp->next=q.front();
            tmp=q.front();
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
        tmp->next=NULL;
        while(root)
        {
            root->next=NULL;
            root=root->right;
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
    cout<<root->val<<endl;
    while(root->left)
    {
        cout<<root->left->val<<" ";
        TreeLinkNode *tmp=root->left->next;
        while(tmp)
        {
            cout<<tmp->val<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
        root=root->left;
    }
}
