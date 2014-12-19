#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty()||grid[0].empty())
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        int i,j;
        for(i=1;i<m;i++)
        {
            grid[i][0]+=grid[i-1][0];
        }
        for(j=1;j<n;j++)
            grid[0][j]+=grid[0][j-1];
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec={{1,8,3},{4,5,6},{7,8,9}};
    cout<<s.minPathSum(vec)<<endl;
}
