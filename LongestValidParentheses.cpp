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
                //还没有匹配的都设置为false
                a[i]=false;
                st.push(i);
            }
            else if(!st.empty()&&s[i]==')')
            {
                //每次匹配设置两个为true
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
