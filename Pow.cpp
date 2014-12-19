#include<iostream>
using namespace std;

class Solution
{
public:
    double pow(double x, int n)
    {
        if(x==0&&n==0)
            return 1;
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n<0)
        {
            n=-n;
            x=1/x;
        }
        if(n%2)
            return x*pow(x*x,n/2);
        else
            return pow(x*x,n/2);
    }
};

int main()
{
    Solution s;
    cout<<s.pow(2,2)<<endl;
}
