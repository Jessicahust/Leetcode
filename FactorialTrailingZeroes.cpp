#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0)
            return 0;
        int count=0;
        while((n=n/5)>0)
        {
            count+=n;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.trailingZeroes(25)<<endl;
}
