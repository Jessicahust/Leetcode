#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret(1,"");
        if(digits.empty())
            return ret;
        string str[]={" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        size_t i,j,k;
        for(i=0;i<digits.size();i++)
        {
            string s=str[digits[i]-'0'];
            vector<string> tmp=ret;
            ret.clear();
            for(j=0;j<tmp.size();j++)
            {
                for(k=0;k<s.size();k++)
                    ret.push_back(tmp[j]+s[k]);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> result=s.letterCombinations(string("31"));
    for(auto a:result)
        cout<<a<<endl;
}
