#include<iostream>
#include<new>
using namespace std;

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
    ListNode *detectCycle(ListNode *head)
    {
        //����һ����������Ҫ2�����
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode *p=head;
        ListNode *pre=head;
        while(p&&p->next)
        {
            p=p->next->next;
            pre=pre->next;
            if(pre==p)
                break;
        }
        if(p==NULL||p->next==NULL)
        {
            return NULL;
        }
        p=head;
        while(pre!=p)
        {
            //�ж�Ҫ����ǰ�棬��Ϊ��ͷ��㿪ʼ����һ����ʱ������ָ���������ͷ��㣬��ʱ������Ҫָ�����
            //if(pre==p)
             //   return pre;
            pre=pre->next;
            p=p->next;
        }
        return p;
    }
    void createList(ListNode *&head)
    {
        ListNode *p=NULL;
        ListNode *cycle=NULL;
        int i=0;
        int arr[10]= {10,9,8,7,6,5,4,3,2,1};
        for(i=0; i<10; i++)
        {
            if(head==NULL)
            {
                head=new ListNode(arr[i]);
                if(head==NULL)
                    return;
                //Ϊ�˴���һ��������¼βָ��
                cycle=head;
            }
            else
            {
                p=new ListNode(arr[i]);
                p->next=head;
                head=p;
            }
        }
        cycle->next=head->next->next->next;
    }
};

int main()
{
    Solution s;
    ListNode *L=NULL;
    s.createList(L);
    ListNode *head=L;
    L=s.detectCycle(L);
    head=L;
    while(L)
    {
        cout<<L->val<<" ";
        L=L->next;
        if(L==head)
            break;
    }
}

