#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.empty())
            return 0;
        int i,j;
        int minH;
        int maxArea=0;
        int n=height.size();
        for(i=0;i<n;i++)
        {
            minH=height[i];
            for(j=i;j<n;j++)
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
    vector<int> height={2,1,5,6,2,3};
    cout<<s.largestRectangleArea(height)<<endl;
}
