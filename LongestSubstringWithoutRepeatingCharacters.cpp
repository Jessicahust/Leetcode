#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        if(s.length()==1)
            return 1;
        size_t i,j,k=0;
        //记录最大长度
        size_t maxLen=0;
        //记录最大长度开始的下标
        size_t index=0;
        for(i=1; i<s.length(); i++)
        {
            j=k;
            while(j<i)
            {
                if(s[j]==s[i])
                {
                    if(i-k>maxLen)
                    {
                        maxLen=i-k;
                        index=k;
                    }
                    k=j+1;
                    break;
                }
                else
                    j++;
            }
        }
        if(i-k>maxLen)
        {
            maxLen=i-k;
            index=k;
        }
        cout<<"index: "<<index<<endl;
        return maxLen;
    }
};

int main()
{
    Solution s;
    string ss="wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    cout<<s.lengthOfLongestSubstring(ss)<<endl;
}
