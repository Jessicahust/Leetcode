#include<map>
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        multimap<int,int> sum;
        size_t i=0;
        for(i=0; i<numbers.size(); i++)
            sum.insert({numbers[i],i});
        auto map_it=sum.begin();
        while(map_it!=sum.end())
        {
            int tmp=target-map_it->first;
            auto iter=sum.find(tmp);
            if(iter!=sum.end())
            {
                if(map_it==iter)
                    iter++;
                return vector<int> {min(map_it->second+1,iter->second+1),max(map_it->second+1,iter->second+1)};
            }
            map_it++;
        }
        return vector<int>();
    }
};

int main()
{
    vector<int> vec={0,4,0,3,0};
    Solution s;
    vector<int> result=s.twoSum(vec,0);
    for(auto a:result)
        cout<<a<<" ";
    cout<<endl;
}
