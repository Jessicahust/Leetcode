#include<iostream>
using namespace std;

class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(target==A[i])
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int A[10]= {2,3,4,5,6,7,8,9,10,1};
    cout<<s.search(A,10,5)<<endl;
}
