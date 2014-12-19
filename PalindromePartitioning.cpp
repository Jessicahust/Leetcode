#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        if(s.empty())
            return vector<vector<string> >();
        vector<vector<string> > ret;
        vector<string> path;
        helper(s,0,ret,path);
        return ret;
    }
    void helper(string s,int start,vector<vector<string> > &ret,vector<string> &path)
    {
        int n=path.size();
        int i;
        int sum=0;
        for(int j=0; j<n; j++)
        {
            sum+=path[j].size();
        }

        if(sum==(int)s.size())
        {
            ret.push_back(path);
            return;
        }
        for(i=1; i<=(int)s.size()&&start+i<=(int)s.size(); i++)
        {
            string tmp=s.substr(start,i);
            if(!isPalindrome(tmp))
                continue;
            path.push_back(tmp);
            helper(s,start+i,ret,path);
            path.pop_back();
        }
    }
    bool isPalindrome(string s)
    {
        if(s.empty())
            return true;
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        if(i>j)
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > result=s.partition(string("ababababababababababababcbabababababababababababa"));
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
