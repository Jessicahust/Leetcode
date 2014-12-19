#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        if(s.empty())
            return 0;
        vector<string> path;
        int min=INT_MAX;
        helper(s,0,path,min);
        return min;
    }
    void helper(string s,int start,vector<string> &path,int &min)
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
            if((int)path.size()-1<min)
                min=path.size()-1;
            return;
        }
        for(i=1; i<=(int)s.size()&&start+i<=(int)s.size(); i++)
        {
            string tmp=s.substr(start,i);
            if(!isPalindrome(tmp))
                continue;
            path.push_back(tmp);
            helper(s,start+i,path,min);
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
    int result=s.minCut(string("abababababab"));
    cout<<result<<endl;
}
