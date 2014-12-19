#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &num,int target)
    {
        if(num.empty())
            return vector<vector<int> >();
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        int n=num.size();
        int i,j;
        for(i=0; i<n-3; i++)
        {
            //只保留第一个不重复的，其余的都删了,因为left会选择重复的
            if(i>=1&&num[i]==num[i-1])
                continue;
            for(j=n-1; j>i+2; j--)
            {
                //只保留最后一个不重复的，其余的都删了,因为right会选择重复的
                if(j<n-1&&num[j+1]==num[j])
                   continue;
                int left=i+1;
                int right=j-1;
                vector<int> tmp;
                while(left<right)
                {
                    //只保留最后一个不重复的，其余的都删了,因为left会选择重复的
                    if(right<j-1&&num[right]==num[right+1])
                        right--;
                    else if(num[i]+num[j]+num[left]+num[right]==target)
                    {
                        tmp= {num[i],num[left],num[right],num[j]};
                        ret.push_back(tmp);
                        left++;
                        right--;
                    }
                    else if(num[i]+num[j]+num[left]+num[right]<target)
                        left++;
                    else if(num[i]+num[j]+num[left]+num[right]>target)
                        right--;
                }
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> vec= {-5,5,4,-3,0,0,4,-2};
    Solution s;
    vector<vector<int> > result=s.fourSum(vec,4);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
    cout<<endl;
}

