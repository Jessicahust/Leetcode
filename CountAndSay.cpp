#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if(n==0)
            return NULL;
        if(n==1)
            return string("1");
        string s="1";
        int i;
        size_t j,k=0;
        for(i=2; i<=n; i++)
        {
            string tmp;
            stringstream ss;
            for(j=1; j<s.length(); j++)
            {
                if(s[k]!=s[j])
                {
                    ss<<j-k;
                    tmp+=ss.str();
                    //注意清空stringstream，不然上次的内容还存在，还有清空操作不是clear()
                    ss.str("");
                    tmp.append(1,s[k]);
                    k=j;
                }
            }
            ss<<j-k;
            tmp+=ss.str();
            ss.str("");
            tmp.append(1,s[k]);
            s=tmp;
            k=0;
        }
        return s;
    }
};
int main()
{
    Solution s;
    for(int i=1; i<=10; i++)
        cout<<s.countAndSay(i)<<endl;
}
