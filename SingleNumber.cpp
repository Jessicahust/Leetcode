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
            auto tmp=map_it;
            tmp++;
            if((tmp)==mp.end())
                return (map_it)->first;
            if(map_it->first!=(tmp)->first)
                break;
            map_it++;
            map_it++;
        }
        return map_it->first;
    }
};

int main()
{
    Solution s;
    int arr[]={2,4,2,4,5};
    cout<<s.singleNumber(arr,5)<<endl;
}
