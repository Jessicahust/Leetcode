#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        if(obstacleGrid.empty()||obstacleGrid[0].empty())
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int path[m][n];
        int i,j;
        if(obstacleGrid[0][0]==1)
            return 0;
        path[0][0]=1;
        for(i=1; i<m; i++)
        {
            if(obstacleGrid[i][0]==1)
                path[i][0]=0;
            else
                path[i][0]=path[i-1][0];
        }
        for(j=1; j<n; j++)
        {
            if(obstacleGrid[0][j]==1)
                path[0][j]=0;
            else
                path[0][j]=path[0][j-1];
        }
        for(i=1; i<m; i++)
        {
            for(j=1; j<n; j++)
            {
                if(obstacleGrid[i][j]==1)
                    path[i][j]=0;
                else
                    path[i][j]=path[i-1][j]+path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec= {{0,0,0},{0,1,0},{0,0,0}};
    cout<<s.uniquePathsWithObstacles(vec)<<endl;
}

