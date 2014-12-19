#include<iostream>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int i=0, j=0, median = m+n;
        double prev=0, last=0;

        if(median<2)
        {
            if (m == 0 && n == 0) return 0;
            if (m==1)
                return A[0];
            else
                return B[0];
        }

        while ( (i+j) <= (median/2) )
        {
            prev = last;
            if (i >= m) //如果A中的元素已经用完，直接取B数组
            {
                last=B[j];
                j++;
            }
            else if (j>=n) //同上
            {
                last = A[i];
                i++;
            }
            else if (A[i]<B[j]) //取A[i] 和 B[j] 中较小的
            {
                last = A[i];
                i++;
            }
            else
            {
                last=B[j];
                j++;
            }
        }

        if ((median & 1) == 0) //偶数个
            return (prev + last) / 2.0;
        else //奇数个
            return last;
    }
};

int main()
{
    Solution s;
    int A[5]= {1,2,3,4,5};
    int B[10]= {6,7,8,9};
    cout<<s.findMedianSortedArrays(A,5,B,4)<<endl;
}
