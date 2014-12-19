#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return vector<string>();
        vector<string> ret;
        string str;
        generate(n,n,ret,str);
        return ret;
    }
    void generate(int left,int right,vector<string> &ret,string &str)
    {
        if(left>right)
            return;
        if(left==0&&right==0)
        {
            ret.push_back(str);
            return;
        }
        if(left>0)
        {
            str.push_back('(');
            generate(left-1,right,ret,str);
            str.pop_back();
        }
        if(right>0)
        {
            str.push_back(')');
            generate(left,right-1,ret,str);
            str.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<string> result=s.generateParenthesis(3);
    for(auto a:result)
        cout<<a<<endl;
}
