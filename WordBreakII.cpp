#include<iostream>
#include<unordered_set>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

class Solution
{
public:
    int space=0;
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        vector<string> ret;
        if(s.empty()||dict.empty())
            return ret;
        string path;
        helper(s,dict,0,ret,path);
        return ret;
    }
    void helper(string s,unordered_set<string> &dict,int start,vector<string> &ret,string &path)
    {
        if((space+s.length())==path.length())
        {
            path.pop_back();
            ret.push_back(path);
            return;
        }
        size_t i;
        int len=path.size();
        for(i=1;i<=s.length()&&start+i<=s.length();i++)
        {
            string tmp=s.substr(start,i);
            if(dict.count(tmp)>0)
            {
                path+=tmp+' ';
                space++;
                helper(s,dict,start+i,ret,path);
                space--;
                path.erase(len,i+1);
            }
        }
    }
};

int main()
{
    unordered_set<string> dict= {"cat", "cats", "and", "sand", "dog"};
    Solution s;
    string ss = "catsanddog";
    vector<string> result=s.wordBreak(ss,dict);
    for(auto a:result)
        cout<<a<<endl;
}


