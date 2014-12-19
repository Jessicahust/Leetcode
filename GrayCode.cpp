#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int i;
        for(i=0;i<pow(2,n);i++)
        {
            ret.push_back((i>>1)^i);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> result=s.grayCode(4);
    for(auto v:result)
        cout<<v<<" ";
    cout<<endl;
}
