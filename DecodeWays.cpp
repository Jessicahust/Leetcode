#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if(s.empty())
            return 0;
        int n=s.size();
        int dp[n+1];
        //dp[i]表示s[0...i-1]的解码方法数目
        dp[0]=1;
        if(s[0]=='0')
            dp[1]=0;
        else
            dp[1]=1;
        int i;
        for(i=2;i<n+1;i++)
        {
            if(s[i-1]=='0')
                dp[i]=0;
            else
                dp[i]=dp[i-1];
            if((s[i-2]=='2'&&s[i-1]<='6')||(s[i-2]=='1'))
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout<<s.numDecodings(string("123456"))<<endl;
}
