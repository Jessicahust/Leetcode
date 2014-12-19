#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i=0;
        int count=0;
        while(i+count<n)
        {
            if(A[i]!=elem)
            {
                i++;
                continue;
            }
            else
            {
                count++;
                swap(A[i],A[n-count]);
            }

        }
        return n-count;
    }
};

int main()
{
    int arr[10]={1,3,4,3,3,3,7,3,4,3};
    Solution s;
    cout<<s.removeElement(arr,10,3)<<endl;
    for(auto a:arr)
        cout<<a<<" ";
    cout<<endl;
}
