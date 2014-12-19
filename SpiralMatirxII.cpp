#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        if(n==0)
            return vector<vector<int> >();
        vector<vector<int> > vec(n,vector<int>(n));
        int i,j;
        int count=1;
        i=0,j=0;
        while(((n%2)&&(count<n*n))||((n%2==0)&&(count<=n*n)))
        {
            for(; j<n-i-1; j++)
            {
                vec[i][j]=count;
                count++;
            }
            for(; i<j; i++)
            {
                vec[i][j]=count;
                count++;
            }
            for(; j>n-i-1; j--)
            {
                vec[i][j]=count;
                count++;
            }
            for(; i>j; i--)
            {
                vec[i][j]=count;
                count++;
            }
            i++;
            j++;
        }
        if(n%2)
            vec[i][j]=count;
        return vec;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result=s.generateMatrix(4);
    for(auto a:result)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
    cout<<endl;
}

