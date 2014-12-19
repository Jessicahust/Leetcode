#include<iostream>
using namespace std;

class Solution {
public:
     // 关键是在于找到规律：
    // 即第i块地方的存水量 = min(第i块左边最高的bar高度, 第i块右边最高的bar的高度) - 第i块地方bar的高度
    // 例如图中，第5块地方的存水量 = min(2,3)-0 = 2
    // 2为其左边最高的bar，即第3块地方的bar
    // 3为其右边最高的bar，即第7块地方的bar，
    // 0为其自身的bar高度
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
