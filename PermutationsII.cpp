#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        if(num.empty())
            return vector<vector<int> >();
        vector<vector<int> > ret {{num[0]}};
        size_t i,j,k;
        for(i=1; i<num.size(); i++)
        {
            vector<int> temp1;
            vector<vector<int> > temp2=ret;
            ret.clear();
            for(j=0; j<temp2.size(); j++)
            {
                temp1=temp2[j];
                k=0;
                size_t ii;
                while((temp1.begin()+k)!=temp1.end())
                {
                    temp1.insert(temp1.begin()+k,num[i]);
                    for(ii=0; ii<ret.size(); ii++)
                    {
                        if(ret[ii]==temp1)
                            break;
                    }
                    if(ii>=ret.size())
                        ret.push_back(temp1);
                    temp1=temp2[j];
                    k++;
                }
                temp1.push_back(num[i]);
                for(ii=0; ii<ret.size(); ii++)
                {
                    if(ret[ii]==temp1)
                        break;
                }
                if(ii>=ret.size())
                    ret.push_back(temp1);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> vec= {3,3,0,0,2,3,2};
    vector<vector<int> > result=s.permuteUnique(vec);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
    cout<<result.size()<<endl;
}

