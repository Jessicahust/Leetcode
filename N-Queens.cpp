#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> path(n,string(n,'.'));
        helper(n,0,res,path);
        return res;
    }
    void helper(int n,int start,vector<vector<string> > &res,vector<string> &path)
    {
        if(start==n)
        {
            res.push_back(path);
            return;
        }
        int i;
        //i用来设置每一列，start代表每一行
        for(i=0;i<n;i++)
        {
            if(isValid(path,start,i))
            {
                path[start][i]='Q';
                helper(n,start+1,res,path);
                path[start][i]='.';
            }
        }
    }
    bool isValid(vector<string> &path,int row,int col)
    {
        int i,j;
        for(i=0;i<row;i++)
            if(path[i][col]=='Q')
                return false;
        for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if(path[i][j]=='Q')
                return false;
        for(i=row-1,j=col+1;i>=0&&j<(int)path.size();i--,j++)
            if(path[i][j]=='Q')
                return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > result=s.solveNQueens(4);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<endl;
        cout<<endl;
    }
}
