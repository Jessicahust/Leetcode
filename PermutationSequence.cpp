#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==0)
            return "";
        int total=factorial(n);
        string str=string("123456789").substr(0,n);
        string ret(n,' ');
        int i;
        for(i=0;i<n;i++)
        {
            int index;
            total=total/(n-i);
            index=(k-1)/total;
            ret[i]=str[index];
            str.erase(index,1);
            k=k-index*total;
        }
        return ret;
    }

    int factorial(int n)
    {
        if(n==0)
            return 0;
        int i;
        int sum=1;
        for(i=1;i<=n;i++)
           sum*=i;
        return sum;
    }
};

int main()
{
    Solution s;
    cout<<s.getPermutation(3,5)<<endl;
}
