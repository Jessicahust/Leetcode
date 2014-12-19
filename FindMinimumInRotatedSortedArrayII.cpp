#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &num)
    {
        int minNum=INT_MAX;
        int i;
        for(i=0; i<(int)num.size(); i++)
        {
            if(num[i]<minNum)
                minNum=num[i];
        }
        return minNum;
    }
};

int main()
{
    Solution s;
    vector<int> num= {10,10,10,10,10,10,1,10,10,10,10};
    cout<<s.findMin(num)<<endl;
}

