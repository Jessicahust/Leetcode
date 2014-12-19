#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        vector<vector<int> > ret;
        vector<int> path;
        int n=num.size();
        sort(num.begin(),num.end());
        bool visited[n];
        memset(visited,false,sizeof(visited));
        helper(num,visited,ret,path);
        return ret;
    }
    void helper(vector<int> &num,bool visited[],vector<vector<int> > &ret,vector<int> &path)
    {
        if(path.size()==num.size())
        {
            ret.push_back(path);
            return;
        }
        int i;
        for(i=0; i<num.size(); i++)
        {
            if(i>0&&num[i-1]==num[i]&&!visited[i-1])
                continue;
            if(!visited[i])
            {
                visited[i]=true;
                path.push_back(num[i]);
                helper(num,visited,ret,path);
                path.pop_back();
                visited[i]=false;
            }
        }
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


