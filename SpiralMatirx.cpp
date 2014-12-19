#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        if(matrix.empty()||matrix[0].empty())
            return vector<int>();
        vector<int> ret;
        int xmin=0;
        int ymin=0;
        int xmax=matrix[0].size()-1;
        int ymax=matrix.size()-1;
        ret.push_back(matrix[0][0]);
        int i=0,j=0;
        while(1)
        {
            while(i<xmax)
                ret.push_back(matrix[j][++i]);
            if(++ymin>ymax)
                break;
            while(j<ymax)
                ret.push_back(matrix[++j][i]);
            if(--xmax<xmin)
                break;
            while(i>xmin)
                ret.push_back(matrix[j][--i]);
            if(--ymax<ymin)
                break;
            while(j>ymin)
                ret.push_back(matrix[--j][i]);
            if(++xmin>xmax)
                break;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > vec= {{1,2}};
    vector<int> result=s.spiralOrder(vec);
    for(auto a:result)
        cout<<a<<" ";
    cout<<endl;
}
