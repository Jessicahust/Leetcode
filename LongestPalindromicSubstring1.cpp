#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if(s.empty())
            return NULL;
        int start=0;
        int end=0;
        int n=s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int i;
        dp[0][0]=true;
        for(i=1;i<n;i++)
        {
            dp[i][i]=true;
            dp[i][i-1]=true;
        }
        int k;//k用于记录从i开始的子串的长度,当长度为1是肯定是回文，从len=2开始判断
        for(k=2;k<=n;k++)
        {
            for(i=0;i<=n-k;i++)
            {
                if(s[i]==s[i+k-1]&&dp[i+1][i+k-2])
                {
                    dp[i][i+k-1]=true;
                    if(k>end-start+1)
                    {
                        start=i;
                        end=i+k-1;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};

int main()
{
    string s1="bbb";
    Solution s;
    cout<<s.longestPalindrome(s1)<<endl;
}

