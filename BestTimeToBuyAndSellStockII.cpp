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
        int sum=0;
        int i;
        for(i=1;i<(int)prices.size();i++)
        {
            if(buy<prices[i])
            {
                sum+=prices[i]-buy;
                buy=prices[i];
            }
            else
                buy=prices[i];
        }
            return sum;
    }
};

int main()
{
    Solution s;
    vector<int> vec={4,7,5,9};
    cout<<s.maxProfit(vec)<<endl;
}

