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
        //�ֱ�Ϊm��n����������ˣ����ĳ�����m+n�����û�н�λ��ֻ��m+n-1λ
        while(*del==0)
        {
            d.erase(del);
            del--;
        }
        //��ֹȫΪ��ʱ����d�����
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
