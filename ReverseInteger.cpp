#include<iostream>
#include<climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        //���x�պõ���INT_MIN,��ô�����Ƚ�xת��Ϊ����Ȼ��ת��Ϊ��������Ϊ����
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
        //���������λ���м����û�м���ȥ�����λ��Ϊ����λ����ô���i��j���10��������i��j���100��
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
