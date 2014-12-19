#include<iostream>
#include<map>
using namespace std;

class Solution
{
public:
    int singleNumber(int A[],int n)
    {
        multimap<int,int> mp;
        int i;
        for(i=0;i<n;i++)
        {
            mp.insert({A[i],i});
        }
        auto map_it=mp.begin();
        while(map_it!=mp.end())
        {
            auto fst=map_it;
            auto snd=map_it;
            fst++;
            snd++;
            snd++;
            if((fst)==mp.end()||snd==mp.end())
                return (map_it)->first;
            if(map_it->first!=(fst)->first||map_it->first!=snd->first)
                break;
            map_it++;
            map_it++;
            map_it++;
        }
        return map_it->first;
    }
};

int main()
{
    Solution s;
    int arr[]={2,4,2,4,2,4,5,5};
    cout<<s.singleNumber(arr,8)<<endl;
}

