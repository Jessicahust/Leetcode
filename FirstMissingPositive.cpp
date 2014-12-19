#include<iostream>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        if(n==0)
            return 1;
        int i=0;
        while(i<n)
        {
            //如果当前位置存放的是正确的顺序，或者要交换的位置存放的是正确的顺序，此时就不交换
            if(A[i]>0&&A[i]<n&&A[i]!=i&&A[A[i]]!=A[i])
                swap(A[i],A[A[i]]);
            else
                i++;
        }
        for(i=1; i<n; i++)
            if(A[i]!=i)
                return i;
        cout<<A[0]<<endl;
        //如果n个元素都存放，则A[0]将会存放的是n，因为数组的下标只有n-1
        return A[0]==n?n+1:n;
    }
};
int main()
{
    Solution s;
    int A[10]= {1,0,2,1,9,10};
    cout<<s.firstMissingPositive(A,2)<<endl;
}
