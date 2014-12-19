#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total=m+n;
        if((m+n)%2)
            return findMedian(A,0,m-1,B,0,n-1,total/2+1);
        else
        {
            int pre=findMedian(A,0,m-1,B,0,n-1,total/2);
            int last=findMedian(A,0,m-1,B,0,n-1,total/2+1);
            return (pre+last)/2;
        }
    }
    double findMedian(int A[],int astart,int aend,int B[],int bstart,int bend,int k)
    {
        int m=aend-astart+1;
        int n=bend-bstart+1;
        if(m>n)
            return findMedian(B,bstart,bend,A,astart,aend,k);
        if(m==0)
            return B[k-1];
        if(k==1)
            return min(A[astart],B[bstart]);
        int partA=min(m,k/2);
        int partB=k-partA;
        if(A[astart+partA-1]<B[bstart+partB-1])
            return findMedian(A,astart+partA,aend,B,bstart,bend,k-partA);
        else if(A[astart+partA-1]>B[bstart+partB-1])
            return findMedian(A,astart,aend,B,bstart+partB,bend,k-partB);
        else
            return A[astart+partA-1];
    }
};

int main()
{
    Solution s;
    int A[5]= {1,2,3,4,5};
    int B[10]= {6,7,8,9};
    cout<<s.findMedianSortedArrays(A,4,B,4)<<endl;
}
