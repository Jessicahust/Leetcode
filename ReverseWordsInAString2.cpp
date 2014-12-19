#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        if(s.empty())
            return;
        stringstream ss(s);
        s.clear();
        stack<string> st;
        string tmp;
        while(ss>>tmp)
        {
            st.push(tmp);
        }
        while(!st.empty())
        {
            tmp=st.top();
            st.pop();
            if(!st.empty())
                s+=tmp+' ';
            else
                s+=tmp;
        }
    }
};

int main()
{
    Solution s;
    string ss="  the   sky   is    blue  ";
    cout<<ss.length()<<endl;
    cout<<ss<<endl;
    s.reverseWords(ss);
    cout<<ss.length()<<endl;
    cout<<ss<<endl;
}


