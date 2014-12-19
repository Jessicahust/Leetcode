#include<iostream>
using namespace std;

class Solution {
public:
     // �ؼ��������ҵ����ɣ�
    // ����i��ط��Ĵ�ˮ�� = min(��i�������ߵ�bar�߶�, ��i���ұ���ߵ�bar�ĸ߶�) - ��i��ط�bar�ĸ߶�
    // ����ͼ�У���5��ط��Ĵ�ˮ�� = min(2,3)-0 = 2
    // 2Ϊ�������ߵ�bar������3��ط���bar
    // 3Ϊ���ұ���ߵ�bar������7��ط���bar��
    // 0Ϊ�������bar�߶�
    int trap(int A[], int n) {
        if(n==0)
            return 0;
        int left[n];
        int right[n];
        int i;
        int sum=0;
        left[0]=A[0];
        for(i=1;i<n;i++)
            left[i]=max(left[i-1],A[i]);
        right[n-1]=A[n-1];
        for(i=n-2;i>=0;i--)
            right[i]=max(right[i+1],A[i]);
        for(i=1;i<n-1;i++)
            sum+=(min(left[i],right[i])-A[i]);
        return sum;
    }
};

int main()
{
    Solution s;
    int A[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(A,12)<<endl;
}
