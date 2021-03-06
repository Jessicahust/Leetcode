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
        int len=s.length();
        if(len==0)
            return true;
        bool dp[len+1];
        memset(dp,0,sizeof(dp));
        int i,j;
        for(i=1; i<=len; i++)
        {
            if(dp[i]==false&&dict.count(s.substr(0,i))>0)
                dp[i]=true;
            if(i==len&&dp[i]==true)
                break;
            if(dp[i]==true)
            {
                for(j=i+1; j<=len; j++)
                {
                    if(dp[j]==false&&dict.count(s.substr(i,j-i))>0)
                        dp[j]=true;
                    if(j==len&&dp[j]==true)
                        break;
                }
            }
        }
        for(auto a:dp)
            cout<<a<<" ";
        cout<<endl;
        if(i==len||j==len)
            return dp[i]||dp[j];
        return false;
    }
};

int main()
{
    unordered_set<string> dict= {"cat", "cats", "and", "sand", "dog"};
    Solution s;
    string ss = "catsanddog";
    cout<<s.wordBreak(ss,dict)<<endl;
}

