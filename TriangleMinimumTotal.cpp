#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        if(triangle.size()==1)
            return triangle[0][0];
        int i,j;
        for(i=(int)triangle.size()-2;i>=0;i--)
        {
            for(j=0;j<(int)triangle[i].size();j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > triangle={{-1},{2,3},{1,-1,-3}};
    cout<<s.minimumTotal(triangle)<<endl;
}
