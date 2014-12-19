#include<iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if(x==0||x==1)
            return x;
        long long mid;
        long long left=1;
        long long right=x/2+1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x)
                left=mid+1;
            else
                right=mid-1;
        }
        return right;
    }
};

int main()
{
    Solution s;
    cout<<s.sqrt(2147483647)<<endl;
}
