#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        char c[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string str="";
        if(n<27)
            return str+c[--n];
        while(n)
        {
            str+=c[(--n)%26];
            n/=26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};

int main()
{
    Solution s;
    cout<<s.convertToTitle(26)<<endl;
}
