#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int i=0;
        //防止j下溢，还是不要声明为无符号的数，那样就可能会无穷循环，结束不了
        int j=matrix[0].size()-1;
        int temp;
        while(i<(int)matrix.size()&&j>=0)
        {
            temp=matrix[i][j];
            if(target==temp)
                return true;
            else if(target<temp)
                j--;
            else if(target>temp)
                i++;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec=
    {
        {-10,-9},
        {-7,-6},
        {-5,-4},
        {-3,-2}
    };
    cout<<s.searchMatrix(vec,-6)<<endl;
}
