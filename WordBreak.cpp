#include<iostream>
#include<unordered_set>
#include<string>
#include<cstring>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        if(s.empty()||dict.empty())
            return false;
        size_t i,j;
        size_t size=1;
        for(i=0; i<s.size(); i+=size)
        {
            for(j=s.size(); j>=i; j--)
            {
                string str=s.substr(i,j-i);
                auto iter=dict.find(str);
                if(iter!=dict.end())
                {
                    size=j-i;
                    break;
                }
            }
            if(j>s.size())
                return false;
        }
        return true;
    }
};

int main()
{
    unordered_set<string> dict={"aaaa","aaa"};
    Solution s;
    string ss="aaaaaaa";
    cout<<s.wordBreak(ss,dict)<<endl;
}
