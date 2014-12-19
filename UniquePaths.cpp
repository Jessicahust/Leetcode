#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0)
            return 0;
        int path[m][n];
        path[0][0]=0;
        int i,j;
        for(i=0;i<m;i++)
            path[i][0]=1;
        for(j=0;j<n;j++)
            path[0][j]=1;
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
                path[i][j]=path[i-1][j]+path[i][j-1];
        }
        return path[m-1][n-1];
    }
};

int main()
{
    Solution s;
    cout<<s.uniquePaths(3,7)<<endl;
}
