#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &num)
    {
        if(num.empty())
            return 0;
        int s=0;
        int t=num.size()-1;
        if(num[s]<num[t])
            return num[s];
        while(s<t)
        {
            int mid=(s+t)/2;
            if(num[mid]<num[t])
                t=mid;
            else
                s=mid+1;
        }
        return num[s];
    }
};

int main()
{
    Solution s;
    vector<int> num={4,5,6,7,8,9,0,1,2,3};
    cout<<s.findMin(num)<<endl;
}
