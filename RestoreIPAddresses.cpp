#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.empty())
            return ret;
        string str;
        helper(s,0,4,ret,str);
        return ret;
    }
    void helper(string &s,int start,int num,vector<string> &ret,string &str)
    {
        if(num==0)
        {
            //删除最后一个.
            str.pop_back();
            if(str.size()==s.size()+3)
            {
                ret.push_back(str);
            }
            return;
        }
        int len=str.length();
        int i;
        //start+i<=(int)s.length()是为了防止最后一个不能达到3个字符而取到空字符
        //i用来限制子串的长度，最多为3个字符
        for(i=1;i<=3&&start+i<=(int)s.length();i++)
        {
            string tmp=s.substr(start,i);
            if(!isValid(tmp))
                continue;
            str+=tmp+'.';
            helper(s,start+i,num-1,ret,str);
            str.erase(len,i+1);
        }
    }
    bool isValid(string s)
    {
        if(s.empty()||s.size()>3)
            return false;
        if(s[0]=='0'&&s.length()>1)
            return false;
        int num=atoi(s.c_str());
        if(num>=0&&num<=255)
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<string> result=s.restoreIpAddresses(string("25525511135"));
    for(auto a:result)
        cout<<a<<endl;
}
