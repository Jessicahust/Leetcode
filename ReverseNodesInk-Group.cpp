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

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head==NULL||head->next==NULL)
            return head;
        int len=0;
        ListNode *p=head;
        ListNode *q=NULL;
        ListNode *pre=NULL;
        while(p)
        {
            len++;
            p=p->next;
        }
        ListNode *dump=new ListNode(0);
        dump->next=head;
        pre=dump;
        p=head;
        int count=0;
        while(p)
        {
            count++;
            q=p->next;
            while(count==k)
            {
                pre=reverse(pre,q);
                count=0;
            }
            p=q;
        }
        return dump->next;
    }
    ListNode *reverse(ListNode *pre,ListNode *q)
    {
        if(pre->next==NULL)
            return NULL;
        if(pre->next->next==NULL)
            return pre->next;
        ListNode *p=pre->next;
        ListNode *pp=NULL;
        ListNode *temp=NULL;
        pp=p->next;
        p->next=NULL;
        while(pp!=q)
        {
            temp=pp;
            pp=pp->next;
            temp->next=NULL;
            temp->next=pre->next;
            pre->next=temp;

        }
        p->next=q;
        pre=p;
        return pre;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {9,8,7,6,5,4,3,2,1,0};
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
    L=s.reverseKGroup(L,3);
    head=L;
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
