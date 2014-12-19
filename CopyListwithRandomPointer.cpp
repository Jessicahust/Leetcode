#include<iostream>
#include<new>
using namespace std;


// Definition for singly-linked list with a random pointer.
struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if(head==NULL)
            return NULL;
        RandomListNode *p=head;
        while(p)
        {
            RandomListNode *q=new RandomListNode(p->label);
            q->next=p->next;
            p->next=q;
            p=q->next;
        }
        p=head;
        while(p)
        {
            if(p->random)
                p->next->random=p->random->next;
            p=p->next->next;
        }
        RandomListNode *retHead = NULL;
        RandomListNode *tRet = NULL;
        p = head;
        while(p)
        {
            if(retHead == NULL)
            {
                retHead = p->next;
                tRet = retHead;
                p->next = p->next->next;
                p = p->next;
            }
            else
            {
                tRet->next = p->next;
                p->next = p->next->next;
                p = p->next;
                tRet = tRet->next;
            }
        }
        return retHead;
    }
    void createList(RandomListNode *&head)
    {
        RandomListNode *p=NULL;
        int i=0;
        int arr[10]= {10,9,8,7,6,5,4,3,2,1};
        for(i=0; i<10; i++)
        {
            if(head==NULL)
            {
                head=new RandomListNode(arr[i]);
                if(head==NULL)
                    return;
            }
            else
            {
                p=new RandomListNode(arr[i]);
                p->next=head;
                head=p;
            }
        }
    }
};

int main()
{
    Solution s;
    RandomListNode *L=NULL;
    s.createList(L);
    RandomListNode *L2=s.copyRandomList(L);
    RandomListNode *p=L2;
    while(p)
    {
        cout<<p->label<<" ";
        p=p->next;
    }
}
