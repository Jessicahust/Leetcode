#include<iostream>
#include<cctype>
#include<climits>
using namespace std;

class Solution
{
public:
    int atoi(const char *str)
    {
        const char *p=str;
        int arr[100]= {0};
        int dot=0;
        char flag='+';
        int i=0;
        while(isspace(*p))
            p++;
        //ע����ŵ��ж�
        if(*p=='-')
        {
            flag='-';
            p++;
        }
        else if(*p=='+')
            p++;
        //���ֵĿ�ʼλ��
        const char *start=p;
        //ע���ַ��������λ�õ��ж�
        while(*p!='\0')
        {
            //ֻ����һ��.����һ�����ͷ��أ���Ϊֻȡ����
            if(*p=='.')
            {
                if(dot)
                    return 0;
                dot++;
                break;
            }
            //ֻ�иտ�ʼ�ĵط��������ֲŻ����ȡ������֮���������ַ����ᱨ������134aa������134
            if(p==start&&!isdigit(*p))
                return 0;
            if(isdigit(*p))
            {
                arr[i]=*p-'0';
                p++;
                i++;
            }
            else
                break;
        }
        long long num=1;
        dot=p-start;
        while(--dot>0)
            num*=10;
        long long sum=0;
        i=0;
        while(p!=start)
        {
            sum+=arr[i]*num;
            //�ڼ���ÿһ�ζ��ж�sum�����ܵȼ������֮���жϣ���Ȼ�����
            if(flag=='+'&&sum>INT_MAX)
                return INT_MAX;
            if(flag=='-'&&-sum<INT_MIN)
                return INT_MIN;
            i++;
            num/=10;
            p--;
        }
        if(flag=='+')
            return sum;
        else
            return -sum;
    }
};

int main()
{
    const char *str="  9223372036854775809";
    Solution s;
    cout<<s.atoi(str)<<endl;
}
