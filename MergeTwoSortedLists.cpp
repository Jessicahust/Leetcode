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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *p=NULL;
        //q始终记录l2中的元素，qq是取出来要插入到l1中的元素
        ListNode *q=NULL;
        ListNode *qq=NULL;
        //pre是p的前驱，插入比p小的元素时需要
        ListNode *pre=NULL;
        if(l1&&l2)
        {
            pre=p=l1;
            qq=q=l2;
            while(p&&q)
            {
                if(p->val<=q->val)
                {
                    pre=p;
                    p=p->next;
                }
                else
                {
                    qq=q;
                    q=q->next;
                    if(l1==p)
                    {
                        qq->next=l1;
                        l1=qq;
                        pre=p=l1;
                        continue;
                    }
                    qq->next=p;
                    pre->next=qq;
                    pre=qq;
                }
            }
            while(q)
            {
                pre->next=q;
                pre=q;
                q=q->next;
            }
        }
        if(l1==NULL)
            l1=l2;
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
    int arr1[10]= {11,9,7,5,3};
    int arr2[10]= {10,8,6,4,2};
    s.createList(L1,arr1);
    s.createList(L2,arr2);
    L=s.mergeTwoLists(L1,L2);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}

