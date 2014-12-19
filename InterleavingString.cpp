#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.empty()&&s2==s3)
            return true;
        if(s2.empty()&&s1==s3)
            return true;
        if(s1.length() + s2.length() != s3.length())
            return false;
        int m=s1.length();
        int n=s2.length();
        bool dp[m+1][n+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        int i,j;
        for(j=1; j<=n; j++)
            if(s2[j-1]==s3[j-1]&&dp[0][j-1])
                dp[0][j]=true;
        for(i=1; i<=m; i++)
            if(s1[i-1]==s3[i-1]&&dp[i-1][0])
                dp[i][0]=true;
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(dp[i-1][j]&&s1[i-1]==s3[i+j-1])
                    dp[i][j]=true;
                if(dp[i][j-1]&&s2[j-1]==s3[i+j-1])
                    dp[i][j]=true;
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string  s3 = "aadbbcbcac";
    cout<<s.isInterleave(s1,s2,s3)<<endl;
}
