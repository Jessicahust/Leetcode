#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        int i,j;
        vector<vector<int> > heights(row,vector<int>(col));
        int ret=0;
        for(j=0; j<col; j++)
            heights[0][j]=matrix[0][j]=='1'?1:0;
        for(i=1; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if(matrix[i][j]=='0')
                    heights[i][j]=0;
                else
                    heights[i][j]=heights[i-1][j]+1;
            }
        }
        for(i=0; i<row; i++)
        {
            int area=largestRectangleArea(heights[i]);
            ret=max(ret,area);
        }
        return ret;
    }
    int largestRectangleArea(vector<int> &height)
    {
        if(height.empty())
            return 0;
        int i,j;
        int minH;
        int maxArea=0;
        int n=height.size();
        for(i=0; i<n; i++)
        {
            minH=height[i];
            for(j=i; j<n; j++)
            {
                minH=min(minH,height[j]);
                maxArea=max(maxArea,minH*(j-i+1));
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > ch={{'0','0','1','0'},{'0','0','0','1'},{'0','1','1','1'},{'0','0','1','1'}};
    cout<<s.maximalRectangle(ch)<<endl;
}
