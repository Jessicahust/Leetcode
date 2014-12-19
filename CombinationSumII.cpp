#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target){
        if(num.empty())
            return vector<vector<int> >();
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        vector<int> path;
        combination(num,0,target,ret,path);
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
            if(i>start&&candidates[i]==candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            combination(candidates,i+1,target-candidates[i],ret,path);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> vec={0,0,10,1,2,7,6,1,5};
    vector<vector<int> > result=s.combinationSum2(vec,8);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}

