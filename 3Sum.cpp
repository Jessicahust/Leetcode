#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> >ret;
        multimap<int,int> sum;
        size_t i=0;
        for(i=0; i<num.size(); i++)
            sum.insert({num[i],i});
        auto map_it=sum.begin();
        while(map_it!=sum.end())
        {
            int target=-map_it->first;
            //�ڶ����������ӵ�һ���������ĺ���λ�ÿ�ʼ
            auto sec=map_it;
            sec++;
            map<int,int>::iterator iter;
            while(sec!=sum.end())
            {
                int tmp=target-sec->first;
                //������������ֻ���ڳ�ȥ��һ���͵ڶ���Ԫ��֮���ʣ�������в���
                auto third=sec;
                third++;
                multimap<int,int> sum1(third,sum.end());
                iter=sum1.find(tmp);
                if(iter!=sum1.end())
                    break;
                sec++;
            }
            if(sec!=sum.end())
            {
                cout<<map_it->first<<endl;
                cout<<sec->first<<" "<<iter->first<<endl;
                vector<int> tmp={map_it->first,sec->first,iter->first};
                for(i=0;i<(int)ret.size();i++)
                {
                    if(ret[i]==tmp)
                        break;
                }
                if(i>=(int)ret.size())
                    ret.push_back(tmp);
            }
            map_it++;
        }
        return ret;
    }
};

int main()
{
    vector<int> vec={-1,0,1,2,-1,-4};
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
