#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        if(num.empty())
            return vector<vector<int> >();
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        int n=num.size();
        int i;
        for(i=0; i<n-2; i++)
        {
            //只保留第一个不重复的，其余的都删了
            if(i>=1&&num[i]==num[i-1])
                continue;
            int target=-num[i];
            int left=i+1;
            int right=n-1;
            vector<int> tmp;
            while(left<right)
            {
                //删除重复元素
                if(right>left&&right<n-1&&num[right+1]==num[right])
                    right--;
                else if(num[left]+num[right]==target)
                {
                    tmp={num[i],num[left],num[right]};
                    ret.push_back(tmp);
                    left++;
                    right--;
                }
                else if(num[left]+num[right]<target)
                    left++;
                else if(num[left]+num[right]>target)
                    right--;
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> vec= {-2,0,1,1,1,1,1,2};
    Solution s;
    vector<vector<int> > result=s.threeSum(vec);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
    cout<<endl;
}
