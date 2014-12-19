#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        if(num.empty())
            return 0;
        set<int> st;
        int len=1;
        for(int i=0; i<(int)num.size(); i++)
            st.insert(num[i]);
        auto k=st.begin();
        k++;
        int count=1;
        for(; k!=st.end(); k++)
        {
            auto tmp=k;
            tmp--;
            if(*tmp+1!=*k)
            {
                if(count>len)
                    len=count;
                count=1;
                continue;
            }
            count++;
        }
        if(count>len)
            len=count;
        return len;
    }
};

int main()
{
    Solution s;
    vector<int> vec= {9,1,4,7,3,-1,0,5,8,-1,6};
    cout<<s.longestConsecutive(vec)<<endl;
}
