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
            //�����ǰλ�ô�ŵ�����ȷ��˳�򣬻���Ҫ������λ�ô�ŵ�����ȷ��˳�򣬴�ʱ�Ͳ�����
            if(A[i]>0&&A[i]<n&&A[i]!=i&&A[A[i]]!=A[i])
                swap(A[i],A[A[i]]);
            else
                i++;
        }
        for(i=1; i<n; i++)
            if(A[i]!=i)
                return i;
        cout<<A[0]<<endl;
        //���n��Ԫ�ض���ţ���A[0]�����ŵ���n����Ϊ������±�ֻ��n-1
        return A[0]==n?n+1:n;
    }
};
int main()
{
    Solution s;
    int A[10]= {1,0,2,1,9,10};
    cout<<s.firstMissingPositive(A,2)<<endl;
}
