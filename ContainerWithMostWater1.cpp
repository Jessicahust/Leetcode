#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        if(height.empty()||height.size()==1)
            return 0;
        int n=height.size();
        int i,j;
        int maxArea=0;
        i=0;
        j=n-1;
        while(i<j)
        {
            int tmp=min(height[i],height[j])*(j-i);
            if(maxArea<tmp)
                maxArea=tmp;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> vec= {2,4,1,3,0,6};
    cout<<s.maxArea(vec)<<endl;
}

