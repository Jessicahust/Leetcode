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
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *p=head->next;
        ListNode *pre=head;
        ListNode *ppre=head;
        ListNode *q=NULL;
        while(p)
        {
            if(p->val!=pre->val)
            {
                if(ppre==head&&ppre->val==pre->val&&pre!=ppre)
                {
                    while(ppre!=p)
                    {
                        q=ppre;
                        ppre=ppre->next;
                        q->next=NULL;
                        delete q;
                    }
                    head=p;
                    ppre=p;
                    pre=p;
                    p=p->next;
                    continue;
                }
                else if(ppre->next!=pre)
                {
                    pre->next=NULL;
                    pre=ppre->next;
                    ppre->next=p;
                    while(pre)
                    {
                        q=pre;
                        pre=pre->next;
                        q->next=NULL;
                        delete q;
                    }
                    pre=p;
                    p=p->next;
                    continue;
                }
                ppre=pre;
                pre=p;
                p=p->next;
            }
            else
            {
                pre=p;
                p=p->next;
            }
        }
        cout<<ppre->val<<endl;
        cout<<pre->val<<endl;
        //如果ppre需要删除，肯定是因为指向头结点，否则ppre指向的结点不会与pre相等
        if(ppre==head&&ppre->val==pre->val&&ppre!=pre)
        {
            while(ppre!=p)
            {
                q=ppre;
                ppre=ppre->next;
                q->next=NULL;
                delete q;
            }
            return NULL;
        }
        else if(ppre->next!=pre)
        {
            pre->next=NULL;
            pre=ppre->next;
            ppre->next=p;
            while(pre)
            {
                q=pre;
                pre=pre->next;
                q->next=NULL;
                delete q;
            }
        }
        return head;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {6,5,5,4,4,3,3,3,2,2};
        for(i=0; i<2; i++)
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

