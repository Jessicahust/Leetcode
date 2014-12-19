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
        //��ֹj���磬���ǲ�Ҫ����Ϊ�޷��ŵ����������Ϳ��ܻ�����ѭ������������
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
