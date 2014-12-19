#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==0)
            return 0;
        int left=0;
        int right=n-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(A[mid]==target)
                return mid;
            else if(A[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        if(left<=right)
            return mid;
        else
            return left;
    }
};

int main()
{
    Solution s;
    int A[10]={3,5,7,8,12,34,65,89,98,100};
    cout<<s.searchInsert(A,10,300)<<endl;
}
