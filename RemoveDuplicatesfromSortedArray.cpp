#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i;
        int count=1;
        //ע������Ϊ�յ����
        if(n==0)
            return 0;
        for(i=1;i<n;i++)
        {
            if(A[i-1]!=A[i])
            {
                //count��¼�м�������ȵ�Ԫ�أ���һ������ȵ�Ԫ���±�Ϊ1���ڶ�������ȵ�Ԫ�ص��±�Ϊ2����������
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
