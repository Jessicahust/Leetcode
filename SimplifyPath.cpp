#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        if(path.empty())
            return "";
        vector<string> ret;
        string tmp;
        stringstream ss(path);
        while(getline(ss,tmp,'/'))
        {
            if(tmp.empty()||tmp==".")
                continue;
            if(tmp=="..")
            {
                if(!ret.empty())
                    ret.pop_back();
            }
            else
                ret.push_back(tmp);
        }
        tmp.clear();
        for(int i=0; i<(int)ret.size(); i++)
        {
            tmp+="/";
            tmp+=ret[i];
        }
        if(ret.empty())
            return "/";
        return tmp;
    }
};

int main()
{
    Solution s;
    string ss="";
    cout<<s.simplifyPath(ss)<<endl;
}
