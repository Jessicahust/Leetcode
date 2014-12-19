#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int count0,count1,count2;
        count0=count1=count2=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(A[i]==0)
                count0++;
            else if(A[i]==1)
                count1++;
            else
                count2++;
        }
        i=0;
        int j=count0;
        int k=count0+count1;
        while(i<count0)
        {
            if(A[i]==0)
                i++;
            else if(A[i]==1)
            {
                swap(&A[i],&A[j]);
                j++;
            }
            else if(A[i]==2)
            {
                swap(&A[i],&A[k]);
                k++;
            }
        }
        while(j<count0+count1)
        {
            if(A[j]==1)
                j++;
            else if(A[j]==2)
            {
                swap(&A[j],&A[k]);
                k++;
            }
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
    int arr[10]={0,1,2,2,1,1,0,2,0,2};
    s.sortColors(arr,10);
    for(auto a:arr)
        cout<<a<<" ";
    cout<<endl;
}
