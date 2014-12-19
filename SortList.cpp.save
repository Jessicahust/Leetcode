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
    ListNode *sortList(ListNode *head)
    {
        if(head==NULL)
            return NULL;
        //递归的结束条件，注意，与对数组的归并排序不同
        if(head->next==NULL)
            return head;
        ListNode *p=head;
        //注意：q不能从head开始，为什么呢？
        ListNode *q=head->next;
        ListNode *l2=NULL;
        while(q&&q->next)
        {
            p=p->next;
            q=q->next->next;
        }
        l2=p->next;
        p->next=NULL;
        return Merge(sortList(head),sortList(l2));
    }
    ListNode *Merge(ListNode *l1,ListNode *l2)
    {
        ListNode *pre=l1;
        ListNode *p=l1;
        ListNode *q=l2;
        while(p&&q)
        {
            if(p->val<=q->val)
            {
                pre=p;
                p=p->next;
                continue;
            }
            else
            {
                l2=q->next;
                q->next=NULL;
                q->next=p;
                if(p==l1)
                    l1=q;
                else
                    pre->next=q;
                pre=q;
                q=l2;
            }
        }
        if(q)
            pre->next=q;
        return l1;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {5,7,6,4,8,3,9,3,10,1};
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
    ListNode *L1=NULL;
    L1=s.sortList(L);
    while(L1)
    {
        cout<<L1->val<<" ";
        L1=L1->next;
    }
}

