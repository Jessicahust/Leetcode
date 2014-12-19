#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

class Solution
{
public:
    int divide(int dividend,int divisor)
    {
        if(divisor==0)
            return dividend>0?INT_MAX:INT_MIN;
        int count=0;
        int bcs=dividend>=0?dividend:-dividend;
        int cs=divisor>0?divisor:-divisor;
        int flag;
        if((dividend>0&&divisor>0)||(dividend<0&&divisor<0))
            flag=1;
        else
            flag=0;
        while(bcs>=cs)
        {
            bcs-=cs;
            count++;
        }
        cout<<INT_MAX<<endl;
        return flag?count:-count;
    }
};

int main()
{
    Solution s;
    cout<<s.divide(2147483646,1)<<endl;
}
