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
                    //һ��������ȵģ��͸��³���
                    if(k-i>maxLen)
                    {
                        start=i;
                        maxLen=k-i;
                    }
                    k=i;
                    //��s[k]�����ʱ����ʱ���ַ�����Ҫ���±Ƚϣ����Բ���k++
                    if(s[i]!=ss[j])
                        j++;
                }
                //��ֹ�����һ���ַ�����ȣ���ʱҲ��Ҫ����
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
