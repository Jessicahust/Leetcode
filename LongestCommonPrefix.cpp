#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
            return "";
        string s1=strs[0];
        string s2;
        size_t len=s1.size();
        for(size_t i=1;i<strs.size();i++)
        {
            s2=strs[i];
            if(s2.size()<len)
                len=s2.size();
            for(size_t j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    len=j;
                    break;
                }
            }
        }
        return s1.substr(0,len);
    }
};
int main()
{
    vector<string> vec={"aaaaai","aaaaa","aaaa","aaab","aaaagg"};
    Solution s;
    cout<<s.longestCommonPrefix(vec)<<endl;
}
