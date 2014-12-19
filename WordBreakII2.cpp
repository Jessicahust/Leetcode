#include<iostream>
#include<unordered_set>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<string> ss;
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=s.size();
        ss.clear();
        bool dp[n];
        memset(dp,false,sizeof(dp));
        for(int i=0; i<n; i++)
            dp[i]=false;
        for(int j=n-1; j>=0; j--)
        {
            for(int i=j; i<n; i++)
            {
                string t(s.begin()+j,s.begin()+i+1);
                if( dict.find(t)!=dict.end() )
                {
                    if( ( i+1<n && dp[i+1])|| i==n-1)
                        dp[j]=true;
                }
            }
        }
        dfs(0,n,s,string (""),dict,dp);
        return ss;
    }
    void dfs(int st,int n,string str,string cur,unordered_set<string> &dict,bool dp[])
    {
        if(st==n)
        {
            ss.push_back(cur);
            return ;
        }
        for(int i=st; i<n; i++)
        {
            string t(str.begin()+st,str.begin()+i+1);
            if((dp[i+1]||i+1==n) &&  (dict.find(t)!=dict.end() ))
            {
                int c=cur.size();
                cur+=t;
                if(i<n-1)
                    cur.push_back(' ');
                dfs(i+1,n,str,cur,dict,dp);
                cur.resize(c);
            }
        }
    }
};

int main()
{
    unordered_set<string> dict= {};
    Solution s;
    string ss = "a";
    vector<string> result=s.wordBreak(ss,dict);
    for(auto a:result)
        cout<<a<<endl;
}



