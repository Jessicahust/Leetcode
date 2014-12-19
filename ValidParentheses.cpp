#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        size_t index=0;
        stack<char> ss;
        while(index<s.length())
        {
            char c;
            switch(s[index])
            {
            case '(' :
            case '[' :
            case '{' :
                ss.push(s[index]);
                break;
            case ')' :
                if(ss.empty())
                    return false;
                c=ss.top();
                if(c!='(')
                    return false;
                ss.pop();
                break;
            case ']' :
                if(ss.empty())
                    return false;
                c=ss.top();
                if(c!='[')
                    return false;
                ss.pop();
                break;
            case '}' :
                if(ss.empty())
                    return false;
                c=ss.top();
                if(c!='{')
                    return false;
                ss.pop();
                break;
            default:
                return false;
            }
            index++;
        }
        if(index==s.length()&&ss.empty())
            return true;
        return false;
    }
};

int main()
{
    string str="]";
    Solution s;
    cout<<s.isValid(str)<<endl;
}
