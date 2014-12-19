#include<iostream>
#include<vector>
#include<new>
#include<cstring>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        if(matrix.empty()||matrix[0].empty())
            return;
        int m=matrix.size();
        int n=matrix[0].size();
        int rflag=0;
        int cflag=0;
        int i,j;
        for(j=0;j<n;j++)
            if(matrix[0][j]==0)
                rflag=1;
        for(i=0;i<m;i++)
            if(matrix[i][0]==0)
                cflag=1;
        for(i=1; i<(int)matrix.size(); i++)
        {
            for(j=1; j<(int)matrix[0].size(); j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(i=1; i<m; i++)
        {
            for(j=1; j<n; j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(rflag)
            for(j=0;j<n;j++)
                matrix[0][j]=0;
        if(cflag)
            for(i=0;i<m;i++)
                matrix[i][0]=0;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec= {{-1,1,0},{0,2,3},{1,-1,-3}};
    s.setZeroes(vec);
    for(auto v:vec)
    {
        for(auto a:v)
            cout<<a<<" ";
        cout<<endl;
    }
}

