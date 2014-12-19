#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if(candidates.empty())
            return vector<vector<int> >();
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ret;
        vector<int> path;
        combination(candidates,0,target,ret,path);
        return ret;
    }

    void combination(vector<int> &candidates,int start,int target,vector<vector<int> > &ret,vector<int> &path)
    {
        if(target<0)
            return;
        if(target==0)
        {
            ret.push_back(path);
            return;
        }
        int i;
        for(i=start;i<(int)candidates.size();i++)
        {
            path.push_back(candidates[i]);
            combination(candidates,i,target-candidates[i],ret,path);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> vec={2,3,6,7};
    vector<vector<int> > result=s.combinationSum(vec,7);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
