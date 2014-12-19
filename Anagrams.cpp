#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        if(strs.empty())
            return vector<string>();
        map<string,int> mp;
        vector<string> ret;
        size_t i;
        for(i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            //第一次直接插入map中
            if(mp.find(s)==mp.end())
            {
                mp[s]=i;
            }
            else
            {
                //第二次，需要将第一个插入map中的string也放入vector中，以后就不要放了
                if(mp[s]>=0)
                {
                    ret.push_back(strs[mp[s]]);
                    mp[s]=-1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> str={"tea","and","ate","eat","den"};
    vector<string> result=s.anagrams(str);
    for(auto s:result)
        cout<<s<<" ";
    cout<<endl;
}
