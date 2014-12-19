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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *p=head;
        ListNode *q=head;
        ListNode *qre=head;
        int len=0;
        while(p)
        {
            len++;
            p=p->next;
        }
        p=head;
        k=k%len;
        if(k==0)
            return head;
        while(q)
        {
            if(k<0)
            {
                qre=q;
                q=q->next;
                p=p->next;
            }
            else
            {
                k--;
                qre=q;
                q=q->next;
            }

        }
        q=p->next;
        p->next=NULL;
        qre->next=head;
        head=q;
        cout<<p->val<<endl;
        return head;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {10,9,8,7,6,5,4,3,2,1};
        for(i=0; i<5; i++)
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
    L=s.rotateRight(L,4);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}

