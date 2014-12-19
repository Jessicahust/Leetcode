#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res(1,"");
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string>tmp;
            for(int j = 0; j < res.size(); j++)
                for(int k = 0; k < numap[digits[i] - '0'].size(); k++)
                    tmp.push_back(res[j] + numap[digits[i] - '0'][k]);
            res = tmp;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> result=s.letterCombinations(string("31"));
    for(auto a:result)
        cout<<a<<endl;
}
