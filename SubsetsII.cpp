#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        if(S.empty())
            return vector<vector<int>>();
        sort(S.begin(),S.end());
        int n=1<<S.size();
        int i=0;
        vector<vector<int> > ret;
        while(i<n)
        {
            vector<int> temp;
            int index=0;
            int j=i;
            while(j>0)
            {
                if(j&1)
                    temp.push_back(S[index]);
                j=j>>1;
                index++;
            }
            int k;
            for(k=0;k<(int)ret.size();k++)
            {
                if(ret[k]==temp)
                    break;
            }
            if(k==(int)ret.size())
                ret.push_back(temp);
            i++;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> vec= {2,1,2};
    vector<vector<int> > result=s.subsetsWithDup(vec);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}

