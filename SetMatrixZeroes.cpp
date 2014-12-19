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
        const int m=matrix.size();
        const int n=matrix[0].size();
        int arr1[m];
        int arr2[n];
        memset(arr1,0,m);
        memset(arr2,0,n);
        int i,j;
        for(i=0; i<(int)matrix.size(); i++)
        {
            for(j=0; j<(int)matrix[0].size(); j++)
            {
                if(matrix[i][j]==0)
                {
                    arr1[i]=1;
                    arr2[j]=1;
                }
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(arr1[i]==1||arr2[j]==1)
                {
                    matrix[i][j]=0;

                }
            }
        }
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
