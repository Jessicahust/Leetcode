#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        if(num.empty())
            return 0;
        sort(num.begin(),num.end());
        int minSum=0;
        int close=INT_MAX;
        int sum;
        int n=num.size();
        int i;
        for(i=0; i<n-2; i++)
        {
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                if(num[i]+num[left]+num[right]<target)
                {
                    sum=num[i]+num[left]+num[right];
                    cout<<sum<<endl;
                    if(target-sum<close)
                    {
                        close=target-sum;
                        minSum=sum;
                    }
                    left++;
                }
                else if(num[i]+num[left]+num[right]>target)
                {
                    sum=num[i]+num[left]+num[right];
                    cout<<sum<<endl;
                    if(sum-target<close)
                    {
                        close=sum-target;
                        minSum=sum;
                    }
                    right--;
                }
                else if(num[i]+num[left]+num[right]==target)
                {
                    close=0;
                    //cout<<"i "<<i<<" left "<<left<<" right "<<right<<endl;
                    //cout<<num[i]<<" "<<num[left]<<" "<<num[right]<<endl;
                    minSum=num[i]+num[left]+num[right];
                    return minSum;
                }
            }
        }
        return minSum;
    }
};
int main()
{
    vector<int> vec= {1,2,3,4};
    Solution s;
    int result=s.threeSumClosest(vec,1);
    cout<<result<<endl;
}

