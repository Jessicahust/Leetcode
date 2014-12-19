#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    string multiply(string num1,string num2)
    {
        string ret;
        int m=num1.length();
        int n=num2.length();
        vector<int> d(m+n,0);
        int i;
        int j;
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                d[m-1+n-1-i-j]+=(num1[i]-'0')*(num2[j]-'0');
        for(auto a:d)
            cout<<a<<" ";
        cout<<endl;
        int carry=0;
        for(i=0; i<m+n; i++)
        {
            d[i]+=carry;
            carry=d[i]/10;
            d[i]%=10;
        }
        auto del=d.end()-1;
        //分别为m和n的两个数相乘，最大的长度是m+n，如果没有进位则只有m+n-1位
        while(*del==0)
        {
            d.erase(del);
            del--;
        }
        //防止全为零时，将d清空了
        if(d.empty())
            return "0";
        for(auto a:d)
            cout<<a<<" ";
        cout<<endl;
        while(del>=d.begin())
        {
            char c=*del+'0';
            ret.push_back(c);
            del--;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string s1="123";
    string s2="123";
    cout<<s.multiply(s1,s2)<<endl;
}
