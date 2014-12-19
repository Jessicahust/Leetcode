#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return helper(string(s),string(p),0,0);
    }
    bool helper(const string s,const string p,size_t i,size_t j)
    {
        if(j==p.length())
            return i==s.length();
         //p.charAt(j+1)!='*'
        if(j==p.length()-1||p[j+1]!='*')
        {
            if(i==s.length()||(s[i]!=p[j]&&p[j]!='.'))
                return false;
            else
                return helper(s,p,i+1,j+1);
        }
        //p.charAt(j+1)=='*'
        while(i<s.length()&&(s[i]==p[j]||p[j]=='.'))
        {
            if(helper(s,p,i,j+2))
                return true;
            i++;
        }
        return helper(s,p,i,j+2);
    }
};

int main()
{
    Solution ss;
    const char *s="aa";
    const char *p=".*bbb";
    cout<<ss.isMatch(s,p)<<endl;
}
