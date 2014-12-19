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
            //��һ��ֱ�Ӳ���map��
            if(mp.find(s)==mp.end())
            {
                mp[s]=i;
            }
            else
            {
                //�ڶ��Σ���Ҫ����һ������map�е�stringҲ����vector�У��Ժ�Ͳ�Ҫ����
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
