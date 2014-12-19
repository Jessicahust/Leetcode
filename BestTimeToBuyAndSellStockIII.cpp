#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        int n=prices.size();
        int i;
        int low=prices[0];
        int left[n];
        left[0]=0;
        for(i=1;i<n;i++)
        {
            low=min(low,prices[i]);
            left[i]=max(left[i-1],prices[i]-low);
        }
        int high=prices[n-1];
        int right[n];
        right[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            high=max(high,prices[i]);
            right[i]=max(right[i+1],high-prices[i]);
        }
        int maxSum=0;
        for(i=0;i<n;i++)
        {
            maxSum=max(maxSum,left[i]+right[i]);
        }
        return maxSum;
    }
};

int main()
{
    Solution s;
    vector<int> vec={1,4,6,8,3,5,9,3,6};
    cout<<s.maxProfit(vec)<<endl;
}
