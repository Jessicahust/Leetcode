#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        if(s.empty())
            return 0;
        bool a[s.length()];
        size_t i;
        for(i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                //��û��ƥ��Ķ�����Ϊfalse
                a[i]=false;
                st.push(i);
            }
            else if(!st.empty()&&s[i]==')')
            {
                //ÿ��ƥ����������Ϊtrue
                a[i]=true;
                a[st.top()]=true;
                st.pop();
            }
            else
                a[i]=false;
        }
        int max=0;
        int count=0;
        for(i=0; i<s.length(); i++)
        {
            if(a[i])
                count++;
            else
                count=0;
            if(count>max)
                max=count;
        }
        return max;
    }
};

int main()
{
    Solution s;
    string str="(()";
    cout<<s.longestValidParentheses(str)<<endl;
}
