#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2)
            return 0;
        sort(num.begin(),num.end());
        int i;
        int maximum=0;
        for(i=0;i<num.size()-1;i++)
        {
            if(num[i+1]-num[i]>maximum)
                maximum=num[i+1]-num[i];
        }
        return maximum;
    }
};


int main()
{
    vector<int> vec={23,4,33,5,34,36,97,68,88,90};
    Solution s;
    cout<<s.maximumGap(vec)<<endl;
}
