#include<iostream>
using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int left=0;
        int right=n-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(A[mid]==target)
                return mid;
            else if(A[mid]<target&&A[mid]>A[right])
                left=mid+1;
            else if(A[mid]<target&&A[mid]<A[right])
            {
                if(target>A[right])
                    right=mid-1;
                else if(target<A[right])
                    left=mid+1;
                else
                    return right;
            }
            else if(A[mid]>target&&A[mid]>A[right])
            {
                if(target>A[right])
                    right=mid-1;
                else if(target<A[right])
                    left=mid+1;
                else
                    return right;
            }
            else if(A[mid]>target&&A[mid]<A[right])
                right=mid-1;
            else
                return -1;
        }
        if(left>right)
            return -1;
        else
            return mid;
    }
};

int main()
{
    Solution s;
    int A[10]= {2,3,4,5,6,7,8,9,10,1};
    cout<<s.search(A,10,5)<<endl;
}
