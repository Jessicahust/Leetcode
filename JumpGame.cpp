#include<iostream>
using namespace std;

class Solution
{
public:
    bool canJump(int A[],int n)
    {
        int maxSum=0;
        int sum=0;
        int i;
        for(i=0;i<=maxSum&&i<n;i++)
        {
            sum=i+A[i];
            if(sum>maxSum)
                maxSum=sum;
            if(maxSum>=n-1)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int A[5]={3,2,1,0,4};
    cout<<s.canJump(A,5)<<endl;
}
