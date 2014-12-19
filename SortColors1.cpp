#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n==0)
            return;
        int i=0;
        int k=0;
        int j=n-1;
        while(k<=j)
        {
            if(A[k]==0)
            {
                swap(&A[k],&A[i]);
                k++;
                i++;
                continue;
            }
            if(A[k]==2)
            {
                swap(&A[k],&A[j]);
                j--;
                continue;
            }
            k++;
        }
    }
    void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
};

int main()
{
    Solution s;
    int arr[11]={0,1,2,2,1,1,0,2,0,2,2};
    s.sortColors(arr,1);
    for(auto a:arr)
        cout<<a<<" ";
    cout<<endl;
}

