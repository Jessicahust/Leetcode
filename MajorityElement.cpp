#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        if(num.empty())
            return -1;
        int n=num.size();
        int i;
        int index=0;
        int count=1;
        for(i=1;i<n;i++)
        {
            if(num[i]==num[index])
            {
                count++;
            }
            else
                count--;
            if(count<0)
            {
                count=1;
                index=i;
            }
        }
        return num[index];
    }
};

int main()
{
    vector<int> num={3,3,3,3,3,3,1,2,4,5,3,45,2,54};
    Solution s;
    cout<<s.majorityElement(num)<<endl;
}
