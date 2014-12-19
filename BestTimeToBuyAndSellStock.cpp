#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if(prices.empty())
            return 0;
        int buy=prices[0];
        int maxSum=0;
        int sum=0;
        int i;
        for(i=1;i<(int)prices.size();i++)
        {
            sum=prices[i]-buy;
            if(sum>maxSum)
                maxSum=sum;
            if(prices[i]<buy)
                buy=prices[i];
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
