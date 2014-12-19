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
    ListNode *removeNthFromEnd(ListNode *&head, int n)
    {
        if(head==NULL)
            return NULL;
        ListNode *p=head;
        ListNode *q=head;
        ListNode *pre=head;
        int i=0;
        while(q&&i<n)
        {
            q=q->next;
            i++;
        }
        //说明没有n个元素
        if(i<n)
           return head;
        while(q)
        {
            pre=p;
            p=p->next;
            q=q->next;
        }
        if(p==head)
        {
            head=head->next;
            delete p;
        }
        else
        {
            pre->next=p->next;
            delete p;
        }
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
    s.removeNthFromEnd(L,5);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}
