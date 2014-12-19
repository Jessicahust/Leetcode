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
    void reorderList(ListNode *head)
    {
        //开始的代码因为没有加入head->next==NULL而不被接受
        if(head==NULL||head->next==NULL)
            return;
        int len=0;
        ListNode *l1=head;
        ListNode *l2=NULL;
        while(l1)
        {
            len++;
            l1=l1->next;
        }
        len=(len+1)/2;
        l1=head;
        while(--len)
        {
            l1=l1->next;
        }
        if(l1->next==NULL)
            return;
        l2=l1->next;
        l1->next=NULL;
        ListNode *p=l2->next;
        l2->next=NULL;
        ListNode *q=NULL;
        while(p)
        {
            q=p->next;
            p->next=NULL;
            p->next=l2;
            l2=p;
            p=q;
        }
        l1=head;
        p=l2;
        while(l1&&l2)
        {
            l2=l2->next;
            p->next=NULL;
            p->next=l1->next;
            l1->next=p;
            p=l2;
            l1=l1->next->next;
        }
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[11]= {10,9,8,7,6,5,4,3,2,1};
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
    ListNode *L=NULL;
    s.createList(L);
    ListNode *head=L;
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    s.reorderList(L);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}

