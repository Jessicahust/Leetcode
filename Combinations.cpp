#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if(n==0||k==0||n<k)
            return vector<vector<int> >();
        vector<vector<int> > ret;
        vector<int> path;
        combinehelper(n,k,1,ret,path);
        return ret;
    }
    void combinehelper(int n,int k,int start,vector<vector<int> > &ret,vector<int> &path)
    {
        if(k==0)
        {
            ret.push_back(path);
            return;
        }
        int i;
        for(i=start;i<=n;i++)
        {
            path.push_back(i);
            combinehelper(n,k-1,i+1,ret,path);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result=s.combine(1,2);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
