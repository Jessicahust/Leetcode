#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        if(height.empty())
            return 0;
        int maxArea=0;
        int i=0;
        int n=height.size();
        stack<int> st;
        int start;
        for(i=0;i<n;i++)
        {
            if(st.empty()||height[i]>height[st.top()])
                st.push(i);
            else
            {
                start=st.top();
                st.pop();
                //注意求宽度时，是减去当前元素的前一个栈顶元素的index
                int width=st.empty()?i:i-st.top()-1;
                maxArea=max(width*height[start],maxArea);
                i--;//处理到栈为空或者栈中的元素都比当前处理的元素小为止
            }
        }
        while(!st.empty())
        {
            start=st.top();
            st.pop();
            int width=st.empty()?n:n-st.top()-1;
            maxArea=max(width*height[start],maxArea);
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> height={1,2,2};
    cout<<s.largestRectangleArea(height)<<endl;
}
