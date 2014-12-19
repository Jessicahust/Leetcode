#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long i=1;
        while(i<=x)
        {
            i*=10;
        }
        i=i/10;
        long long j=10;
        while(j<=i)
        {
            if(x/i!=(x%j)/(j/10))
                return false;
            x=x%i;
            i/=10;
            j*=10;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(1001)<<endl;
}
