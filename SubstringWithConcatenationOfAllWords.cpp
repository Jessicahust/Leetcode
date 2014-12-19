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
        map<string,int> mp;//��¼L��ÿһ��string���ֵĴ���
        map<string,int> word; //��¼��S���ҵ���L��string�Ĵ������������mp�еģ�˵���ҵ��ظ���
        size_t i;
        for(i=0;i<L.size();i++)
            mp[L[i]]++;
        size_t idx=0;
        //idx֮�����ٻ�ʣ��L�������ַ����ĳ���
        while(idx<=S.length()-n*L.size())
        {
            word.clear();
            int flag=true;
            //i֮�����ٻ�ʣ��һ���ַ����ĳ���n��Ҫȡn���ȵ��Ӵ�
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
