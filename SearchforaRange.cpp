#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        if(n==0)
            return vector<int>{-1,-1};
        int mid;
        int left=0;
        int right=n-1;
        int ll=-1;
        int rr=-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(A[mid]<=target)
            {
                left=mid+1;
            }
            else
                right=mid-1;
        }
        if(A[right]==target)
            rr=right;
        left=0;
        right=n-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(A[mid]>=target)
                right=mid-1;
            else
                left=mid+1;
        }
        if(A[left]==target)
            ll=left;
        return vector<int>{ll,rr};
    }
};

int main()
{
    Solution s;
    int arr[6]={5};
    vector<int> result=s.searchRange(arr,1,1);
    for(auto a:result)
        cout<<a<<" ";
    cout<<endl;
}
