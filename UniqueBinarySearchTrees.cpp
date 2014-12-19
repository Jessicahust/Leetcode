#include<iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n<0)
            return 0;
        if(n==1||n==0)
            return 1;
        int result=1;
        int i;
        for(i=2;i<=n;++i)
            result=(4*i-2)*result/(i+1);
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.numTrees(4)<<endl;
}

