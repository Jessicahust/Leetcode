#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len=s.length();
        if(len==0)
            return true;
        int i;
        for(i=1;i<=len;i++)
        {
            if(dict.count(s.substr(0,i))>0&&wordBreak(s.substr(i,len-i),dict))
                return true;
        }
        return false;
    }
};

int main()
{
    unordered_set<string> dict={"aaaa","aaa"};
    Solution s;
    string ss="aaaaaa";
    cout<<s.wordBreak(ss,dict)<<endl;
}
