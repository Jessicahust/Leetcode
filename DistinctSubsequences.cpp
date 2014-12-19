#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int slen=S.length();
        int tlen=T.length();
        if(tlen==0)
            return 1;
        if(slen==0&&tlen)
            return 0;
        int dp[slen+1][tlen+1];
        dp[0][0]=1;
        int i,j;
        for(i=1;i<=slen;i++)
            dp[i][0]=1;
        for(i=1;i<=tlen;i++)
            dp[0][i]=0;
        for(i=1;i<=slen;i++)
        {
            for(j=1;j<=tlen;j++)
            {
                if(S[i-1]==T[j-1])
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[slen][tlen];
    }
};

int main()
{
    Solution s;
    string S="rabbbit";
    string T="rabbit";
    cout<<s.numDistinct(S,T)<<endl;
}
