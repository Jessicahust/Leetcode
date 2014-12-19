#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        if(matrix.empty())
            return;
        vector<vector<int> > temp=matrix;
        int i,j;
        int n=matrix.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                matrix[j][n-i-1]=temp[i][j];
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec={{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(vec);
    for(auto a:vec)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
