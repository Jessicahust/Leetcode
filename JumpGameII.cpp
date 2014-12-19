#include<iostream>
using namespace std;

class Solution
{
public:
    int jump(int A[],int n)
    {
        int count=0;
        int maxSum=0;
        int sum=0;
        int reach=0;
        int i;
        for(i=0; i<=maxSum&&i<n; i++)
        {
            if(i>reach)
            {
                count++;
                reach=maxSum;
            }
            sum=i+A[i];
            if(sum>maxSum)
            {
                maxSum=sum;
            }
        }
        if(maxSum>=n-1)
            return count;
        return 0;
    }
};

int main()
{
    Solution s;
    int A[15]= {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout<<s.jump(A,15)<<endl;
}

