#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
        if(s2.empty())
        {
            s1.push(x);
            s2.push(x);
            return;
        }
        int tmp=s1.top();
        if(x<=tmp)
            s1.push(x);
        s2.push(x);
    }

    void pop() {
        if(!s2.empty())
        {
            if(s1.top()==s2.top())
                s1.pop();
            s2.pop();
        }
    }

    int top() {
        if(!s2.empty())
            return s2.top();
        return 0;
    }
//s1Ϊ�յ�ʱ��s2ͬ��Ҳ��Ϊ��
    int getMin() {
        if(!s1.empty())
            return s1.top();
        return 0;
    }
private:
    stack<int> s1;//�����Сֵ
    stack<int> s2;//������е�Ԫ��
};

int main()
{
    MinStack minstack;
    minstack.push(100);
    minstack.push(24);
    minstack.push(30);
    cout<<minstack.getMin()<<endl;
}
