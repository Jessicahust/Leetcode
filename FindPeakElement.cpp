#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if(num.empty())
            return -1;
        if(num.size()==1||num[0]>num[1])
            return 0;
        int i=1;
        int n=num.size();
        while(i<n-1)
        {
            if(num[i]>num[i-1]&&num[i]>num[i+1])
                return i;
            i++;
        }
        if(i==n-1&&num[i]>num[i-1])
            return i;
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> vec={1,2};
    cout<<s.findPeakElement(vec)<<endl;
}
