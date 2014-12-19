#include<iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        int i,j;
        int count=0;
        if(n<3)
            return n;
        i=0;
        for(j=1; j<n; j++)
        {
            if(A[j]==A[j-1])
            {
                A[j-count]=A[j];
                continue;
            }
            else
            {
                if(j-i>=3)
                    count+=j-i-2;
                A[j-count]=A[j];
                i=j;
            }
        }
        if(j-i>=3)
            count+=j-i-2;
        return n-count;
    }
};

int main()
{
    Solution s;
    int arr[10]= {1,1,1,2,2,2,3,3,3,4};
    int len=s.removeDuplicates(arr,10);
    cout<<len<<endl;
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
