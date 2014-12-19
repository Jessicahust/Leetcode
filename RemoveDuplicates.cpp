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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pp=NULL;
        ListNode *p=NULL;
        ListNode *q=NULL;
        if(head&&head->next)
        {
            pp=head;
            p=head->next;
            while(p)
            {
                if(pp->val==p->val)
                {
                    q=p;
                    pp->next=q->next;
                    p=q->next;
                    delete q;
                }
                else
                {
                    pp=p;
                    p=p->next;
                }
            }
        }
        return head;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {5,5,5,4,4,3,3,3,2,1};
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
    L=s.deleteDuplicates(L);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}
