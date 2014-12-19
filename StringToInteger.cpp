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
        //注意符号的判断
        if(*p=='-')
        {
            flag='-';
            p++;
        }
        else if(*p=='+')
            p++;
        //数字的开始位置
        const char *start=p;
        //注意字符数组结束位置的判断
        while(*p!='\0')
        {
            //只能有一个.，且一遇到就返回，因为只取整数
            if(*p=='.')
            {
                if(dot)
                    return 0;
                dot++;
                break;
            }
            //只有刚开始的地方不是数字才会错误，取完数字之后后面出现字符不会报错，例如134aa，返回134
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
            //在计算每一次都判断sum，不能等计算完成之后判断，不然会溢出
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
