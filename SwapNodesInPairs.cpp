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
    ListNode *swapPairs(ListNode *head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *p=head;
        ListNode *pre=head;
        ListNode *qq=NULL;
        ListNode *q=NULL;
        while(p&&p->next)
        {
            q=p->next;
            p->next=NULL;
            qq=q->next;
            q->next=NULL;
            q->next=p;
            p->next=qq;
            if(p==head)
            {
                head=q;
            }
            else
                pre->next=q;
            pre=p;
            p=p->next;
        }
        return head;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {7,5,6,4,1,3,9,8,2,10};
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
    L=s.swapPairs(L);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}


