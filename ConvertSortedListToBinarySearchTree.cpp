#include<iostream>
#include<new>
#include<vector>
#include<cmath>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if(head==NULL)
            return NULL;
        TreeNode *root=NULL;
        if(head->next==NULL)
        {
            root=new TreeNode(head->val);
            return root;
        }
        ListNode *p=head;
        ListNode *q=head;
        ListNode *pre=head;
        while(q&&q->next)
        {
            q=q->next->next;
            pre=p;
            p=p->next;
        }
        pre->next=NULL;
        q=p->next;
        p->next=NULL;
        root=new TreeNode(p->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(q);
        return root;
    }
    int maxDepth(TreeNode *root)
    {
        if(root)
        {
            if(root->left==NULL&&root->right==NULL)
                return 1;
            int leftDepth=maxDepth(root->left);
            int rightDepth=maxDepth(root->right);
            return leftDepth>= rightDepth ?(leftDepth+1):(rightDepth+1);
        }
        return 0;
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
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {9,8,5,4,4,3,3,3,2,1};
        for(i=0; i<10; i++)
        {
            if(head==NULL)
            {
                head=new ListNode(arr[i]);
                if(head==NULL)
                    return;
            }
            else
            {
                p=new ListNode(arr[i]);
                p->next=head;
                head=p;
            }
        }
    }
};

int main()
{
    Solution s;
    TreeNode *root=NULL;
    ListNode *L=NULL;
    s.createList(L);
    root=s.sortedListToBST(L);
    s.inorder(root);
    cout<<endl;
    cout<<s.maxDepth(root)<<endl;
}


