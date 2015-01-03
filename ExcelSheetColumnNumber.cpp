#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        int n=strlen(s.c_str());
        int i;
        int count=n-1;
        for(i=0;i<n;i++)
        {
            double p=pow(26,count);
            sum+=(s[i]-'A'+1)*p;
            count--;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout<<s.titleToNumber("AB")<<endl;
}
