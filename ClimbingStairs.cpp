#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int n1=1;
        int n2=2;
        int sum=0;
        while(n>2)
        {
            sum=n1+n2;
            n1=n2;
            n2=sum;
            n--;
        }
        return sum;
    }
};

int main()
{
    int n=5;
    Solution s;
    cout<<s.climbStairs(n)<<endl;
}
