#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int n=L[0].size();
        if(S.length()<n*L.size())
            return ret;
        map<string,int> mp;//记录L中每一个string出现的次数
        map<string,int> word; //记录在S中找到的L中string的次数，如果大于mp中的，说明找到重复的
        size_t i;
        for(i=0;i<L.size();i++)
            mp[L[i]]++;
        size_t idx=0;
        //idx之后至少还剩下L中所有字符串的长度
        while(idx<=S.length()-n*L.size())
        {
            word.clear();
            int flag=true;
            //i之后至少还剩下一个字符串的长度n，要取n长度的子串
            for(i=idx;i<=idx+n*(L.size()-1);i+=n)
            {
                string tmp=S.substr(i,n);
                if(mp.find(tmp)==mp.end())
                {
                    flag=false;
                    break;
                }
                word[tmp]++;
                if(word[tmp]>mp[tmp])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ret.push_back(idx);
            idx++;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> L={"foo", "bar"};
    vector<int> result=s.findSubstring(string("barbarfoothefoobarman"),L);
    for(auto a:result)
        cout<<a<<" ";
    cout<<endl;
}
