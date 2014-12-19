#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if(s.empty())
            return NULL;
        string ss;
        int i;
        int j,k;
        for(i=s.length()-1; i>=0; i--)
        {
            ss.push_back(s[i]);
        }
        int maxLen=0;
        int start=0;
        for(i=0; i<(int)s.length(); i++)
        {
            k=i;
            j=3;
            while(j<(int)ss.length())
            {
                if(s[k]==ss[j])
                {
                    k++;
                    j++;
                    continue;
                }
                else
                {
                    //一遇到不相等的，就更新长度
                    if(k-i>maxLen)
                    {
                        start=i;
                        maxLen=k-i;
                    }
                    k=i;
                    //与s[k]不相等时，此时的字符还需要重新比较，所以不能k++
                    if(s[i]!=ss[j])
                        j++;
                }
                //防止到最后一个字符都相等，此时也需要更新
                if(k-i>maxLen)
                {
                    start=i;
                    maxLen=k-i;
                }
            }
            if(k-i>maxLen)
            {
                start=i;
                maxLen=k-i;
            }
        }
        return s.substr(start,maxLen);
    }
};

int main()
{
    string s1="12211331";
    Solution s;
    cout<<s.longestPalindrome(s1)<<endl;
}
