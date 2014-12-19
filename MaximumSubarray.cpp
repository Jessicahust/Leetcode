#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0)
            return 0;
        int maxSum=0;
        int sum=0;
        int i;
        int max=INT_MIN;
        for(i=0;i<n;i++)
        {
            if(A[i]>=0)
               break;
            if(A[i]>max)
                max=A[i];
        }
        if(i>=n)
            return max;
        for(i=0;i<n;i++)
        {
            sum+=A[i];
            if(maxSum<sum)
            {
                maxSum=sum;
            }
            if(sum<0)
                sum=0;
        }
        return maxSum;
    }
};

int main()
{
    Solution s;
    int A[10]={-2,-3,-8,0};
    cout<<s.maxSubArray(A,10)<<endl;
}
