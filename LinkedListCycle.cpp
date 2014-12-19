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
    bool hasCycle(ListNode *head)
    {
        if(head==NULL||head->next==NULL)
            return false;
        ListNode *pre=head;
        ListNode *p=head;
        while(p&&p->next)
        {
            p=p->next->next;
            pre=pre->next;
            if(p==pre)
                return true;
        }
        return false;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        ListNode *cycle=NULL;
        int i=0;
        int arr[10]= {5,5,5,4,4,3,3,3,2,1};
        for(i=0; i<10; i++)
        {
            if(head==NULL)
            {
                head=new ListNode(arr[i]);
                if(head==NULL)
                    return;
                cycle=head;
            }
            else
            {
                p=new ListNode(arr[i]);
                p->next=head;
                head=p;
            }
        }
        cycle->next=head->next->next;
    }
};

int main()
{
    Solution s;
    ListNode *L=NULL;
    s.createList(L);
    cout<<s.hasCycle(L)<<endl;
}

