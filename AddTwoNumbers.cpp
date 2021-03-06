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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p=l1;
        ListNode *pre=l1;
        ListNode *q=l2;
        int carry=0;
        while(p&&q)
        {
            if(p->val+q->val+carry>9)
            {
                p->val=(p->val+q->val+carry)%10;
                carry=1;
            }
            else
            {
                 p->val+=q->val+carry;
                 carry=0;
            }
            pre=p;
            p=p->next;
            q=q->next;
        }
        if(q)
            pre->next=q;
        while(q)
        {
            if(q->val+carry>9)
            {
                q->val=(q->val+carry)%10;
                carry=1;
            }
            else
            {
                q->val+=carry;
                carry=0;
                break;
            }
            pre=q;
            q=q->next;
        }
        while(p)
        {
            if(p->val+carry>9)
            {
                p->val=(p->val+carry)%10;
                carry=1;
            }
            else
            {
                p->val+=carry;
                carry=0;
                break;
            }
            pre=p;
            p=p->next;
        }
        if(carry)
        {
            p=new ListNode(1);
            pre->next=p;
        }
        return l1;
    }
    void createList(ListNode *&head,int *arr)
    {
        ListNode *p=NULL;
        int i=0;
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
    ListNode *L1=NULL;
    ListNode *L2=NULL;
    ListNode *L=NULL;
    int arr1[10]= {1,9,7,5,3};
    int arr2[10]= {0,8,6,4,2};
    s.createList(L1,arr1);
    s.createList(L2,arr2);
    L=s.addTwoNumbers(L1,L2);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}

