#include<iostream>
#include<climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        //如果x刚好等于INT_MIN,那么不能先将x转换为正数然后转换为负数，因为对于
        if(x==0||x==INT_MIN)
            return 0;
        int flag=1;
        if(x<0)
        {
            x=-x;
            flag=-1;
        }
        long long i=1;
        long long j=10;
        while(i<=x)
        {
            i*=10;
        }
        i=i/10;
        long long sum=0;
        while(j<=i)
        {
            sum+=(x/i)*(j/10)+(x%j)/(j/10)*i;

            if(flag==1&&sum>INT_MAX)
                return 0;
            else if(flag==-1&&-sum<INT_MIN)
                return 0;
            x=x%i;
            i/=10;
            j*=10;
        }
        //如果是奇数位，中间的数没有加上去，如果位数为奇数位，那么最后i与j相差10倍，否则i与j相差100倍
        if(j==i*10)
            sum+=(x/i)*(j/10);
        if(flag==1&&sum>INT_MAX)
            return 0;
        else if(flag==-1&&-sum<INT_MIN)
            return 0;
        return flag*sum;
    }
};
int main()
{
    Solution s;
    cout<<s.reverse(-2147483648)<<endl;
}
