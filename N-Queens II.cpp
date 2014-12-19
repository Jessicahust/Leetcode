#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution
{
public:
    int res=0;
    int totalNQueens(int n)
    {

        vector<int> state(n,-1);
        helper(n,0,state);
        return res;
    }
    void helper(int n,int start,vector<int> &state)
    {
        if(start==n)
        {
            res++;
            return;
        }
        int i;
        for(i=0; i<n; i++)
        {
            if(isValid(state,start,i))
            {
                state[start]=i;
                helper(n,start+1,state);
                state[start]=-1;
            }
        }
    }
    bool isValid(vector<int> &state,int row,int col)
    {
        int i;
        for(i=0; i<row; i++)
            if(state[i]==col||row-i==abs(state[i]-col))
                return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.totalNQueens(4)<<endl;
}
