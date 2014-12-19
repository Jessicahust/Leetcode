#include<iostream>
#include<new>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA==NULL||headB==NULL)
            return NULL;
        int lenA=length(headA);
        int lenB=length(headB);
        int len=0;
        ListNode *p=headA;
        ListNode *q=headB;
        if(lenA>=lenB)
        {
            len=lenA-lenB;
            while(p&&q)
            {
                if(p&&len)
                {
                    len--;
                    p=p->next;
                    continue;
                }
                if(p->val!=q->val)
                {
                    p=p->next;
                    q=q->next;
                    continue;
                }
                break;
            }
        }
        else
        {
            len=lenB-lenA;
            while(p&&q)
            {
                if(q&&len)
                {
                    len--;
                    q=q->next;
                    continue;
                }
                if(p->val!=q->val)
                {
                    p=p->next;
                    q=q->next;
                    continue;
                }
                break;
            }
        }
        if(p&&q)
            return p;
        else
            return NULL;
    }
    int length(ListNode *head)
    {
        if(head==NULL)
            return 0;
        ListNode *p=head;
        int len=0;
        while(p)
        {
            len++;
            p=p->next;
        }
        return len;
    }
    void createList(ListNode *&head,int *arr,int n)
    {
        ListNode *p=NULL;
        int i=0;
        for(i=0; i<n; i++)
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
    ListNode *L1=NULL;
    ListNode *L2=NULL;
    ListNode *L=NULL;
    int arr1[10]= {12,11,9,7,5,3,1,0};
    int arr2[10]= {12,11,8,6,4,2};
    s.createList(L1,arr1,8);
    s.createList(L2,arr2,6);
    L=s.getIntersectionNode(L1,L2);
    cout<<L->val<<endl;
}


