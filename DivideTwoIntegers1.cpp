#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        unsigned int divid,divis;
        long long res=0;
        if(dividend==INT_MIN)
        {
            res = 1;
            dividend +=abs(divisor);
        }
        divid=abs(dividend);
        divis=abs(divisor);
        while(divid>=divis)
        {
            int digit = 0;
            while(divis<=divid)
            {
                divis<<= 1;
                digit++;
            }
            divid-=divis>>1;
            res+=1<<(digit-1);
            divis=abs(divisor);
        }
        return (dividend>0)^(divisor>0)?-res:res;
    }
};
int main()
{
    Solution s;
    cout<<s.divide(-2147483648,2)<<endl;
}
