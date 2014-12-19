#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        if(ratings.empty())
            return 0;
        int n=ratings.size();
        int num[n];
        num[0]=1;
        int i;
        for(i=1; i<n; i++)
        {
            if(ratings[i]>ratings[i-1])
                num[i]=num[i-1]+1;
            else
                num[i]=1;
        }
        for(i=n-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1]&&num[i]<=num[i+1])
                num[i]=num[i+1]+1;
        }
        int res=0;
        for(i=0; i<n; i++)
            res+=num[i];
        return res;
    }
};

int main()
{
    vector<int> ratings= {2,3,5,2,7,8,7,5,6,4};
    Solution s;
    cout<<s.candy(ratings)<<endl;
}
