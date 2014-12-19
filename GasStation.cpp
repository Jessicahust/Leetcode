#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i,j=-1;
        int sum=0;
        int total=0;
        for(i=0;i<(int)gas.size();i++)
        {
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0)
            {
                sum=0;
                j=i;
            }
        }
        return total>=0?j+1:-1;
    }
};

int main()
{
    Solution s;
    vector<int> gas={0,4,5};
    vector<int> cost={1,2,6};
    cout<<s.canCompleteCircuit(gas,cost)<<endl;
}
