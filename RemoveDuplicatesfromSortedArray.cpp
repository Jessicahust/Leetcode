#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i;
        int count=1;
        //注意数组为空的情况
        if(n==0)
            return 0;
        for(i=1;i<n;i++)
        {
            if(A[i-1]!=A[i])
            {
                //count记录有几个不相等的元素，第一个不相等的元素下标为1，第二个不相等的元素的下标为2，依次类推
                count++;
                A[count-1]=A[i];
            }
        }
        return count;
    }
};

int main()
{
    int arr[10]={1,2,3,3,3,4,4,5,5,6};
    Solution s;
    cout<<s.removeDuplicates(arr,10)<<endl;
    for(auto a:arr)
        cout<<a<<" ";
    cout<<endl;
}
