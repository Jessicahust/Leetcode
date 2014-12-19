#include<iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(A[i]>=B[j])
            {
                A[k--]=A[i--];
            }
            else
            {
                A[k--]=B[j--];
            }
        }
        while(i>=0)
        {
            A[k--]=A[i--];
        }
        while(j>=0)
        {
            A[k--]=B[j--];
        }
    }
};

int main()
{
    int A[10]={1,3,5,7,9};
    int B[5]={2,4,6,8,10};
    Solution s;
    s.merge(A,5,B,5);
    for(auto a:A)
        cout<<a<<" ";
    cout<<endl;
}
