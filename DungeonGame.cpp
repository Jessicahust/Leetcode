#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.empty()||dungeon[0].empty())
            return 1;
        int m=dungeon.size();
        int n=dungeon[0].size();
        int i,j;
        int dp[m][n];
        dp[m-1][n-1]=max(1-dungeon[m-1][n-1],1);
        for(i=m-2;i>=0;i--)
            dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],1);
        for(j=n-2;j>=0;j--)
            dp[m-1][j]=max(dp[m-1][j+1]-dungeon[m-1][j],1);
        for(i=m-2;i>=0;i--)
        {
            for(j=n-2;j>=0;j--)
            {
                //可以从上下两个方向到达
                dp[i][j]=min(max(dp[i][j+1]-dungeon[i][j],1),max(dp[i+1][j]-dungeon[i][j],1));
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout<<s.calculateMinimumHP(vec)<<endl;
}
