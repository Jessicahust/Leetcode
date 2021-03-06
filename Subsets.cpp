#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &S)
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
            ret.push_back(temp);
            i++;
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> vec= {2,1,3};
    vector<vector<int> > result=s.subsets(vec);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
