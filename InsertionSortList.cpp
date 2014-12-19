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
    ListNode *insertionSortList(ListNode *&head)
    {
        if(head==NULL)
            return NULL;
        ListNode *pre=head;
        ListNode *p=head;
        ListNode *q=head->next;
        ListNode *tmp=NULL;
        head->next=NULL;
        while(q)
        {
            tmp=q->next;
            q->next=NULL;
            while(p)
            {
                if(q->val>p->val)
                {
                    pre=p;
                    p=p->next;
                }
                else
                {
                    if(p==head)
                    {
                        q->next=head;
                        head=q;
                    }
                    else
                    {
                        q->next=p;
                        pre->next=q;
                    }
                    break;
                }
            }
            if(p==NULL)
                pre->next=q;
            //每一个元素插入完成之后都要将p和pre指向头结点，从头开始比较插入
            p=pre=head;
            q=tmp;
        }
        return head;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        int i=0;
        int arr[10]= {3,4,1,4,6,3,7,2,1,10};
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
    L=s.insertionSortList(L);
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
    }
}
