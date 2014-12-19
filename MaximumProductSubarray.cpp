#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==0)
            return 0;
        int maxPro[n];
        int minPro[n];
        minPro[0]=maxPro[0]=A[0];
        int i;
        for(i=1;i<n;i++)
        {
            maxPro[i]=max(A[i],max(maxPro[i-1]*A[i],minPro[i-1]*A[i]));
            minPro[i]=min(A[i],min(maxPro[i-1]*A[i],minPro[i-1]*A[i]));
        }
        int max=maxPro[0];
        for(i=0;i<n;i++)
        {
            if(max<maxPro[i])
                max=maxPro[i];
        }
        return max;
    }
};

int main()
{
    Solution s;
    int arr[10]={2,3,-2,4};
    cout<<s.maxProduct(arr,4)<<endl;
}
