#include<iostream>
#include<new>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if(head==NULL)
            return NULL;
        ListNode *p=head;
        ListNode *pre=head;
        ListNode *qpre=NULL;
        ListNode *q=NULL;
        int count=0;
        while(p)
        {
            count++;
            if(count==m)
            {
                qpre=pre;
                q=p;
            }
            else if(count==n)
                break;
            pre=p;
            p=p->next;
        }
        cout<<p->val<<endl;
        cout<<q->val<<endl;
        if(p==NULL||p==q)
            return head;
        ListNode *pp=p->next;
        ListNode *qq=NULL;
        p->next=NULL;
        p=q->next;
        cout<<p->val<<endl;
        q->next=pp;
        while(p)
        {
            qq=p->next;
            cout<<p->val<<endl;
            p->next=q;
            q=p;
            cout<<q->val<<endl;
            p=qq;
        }
        cout<<q->val<<endl;
        if(m!=1)
            qpre->next=q;
        else
            head=q;
        return head;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {9,8,5,4,4,3,3,3,2,1};
        for(i=0; i<3; i++)
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
    ListNode *L=NULL;
    s.createList(L);
    ListNode *head=L;
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    L=s.reverseBetween(L,2,3);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}


