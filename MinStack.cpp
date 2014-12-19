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
//s1为空的时候，s2同样也会为空
    int getMin() {
        if(!s1.empty())
            return s1.top();
        return 0;
    }
private:
    stack<int> s1;//存放最小值
    stack<int> s2;//存放所有的元素
};

int main()
{
    MinStack minstack;
    minstack.push(100);
    minstack.push(24);
    minstack.push(30);
    cout<<minstack.getMin()<<endl;
}
