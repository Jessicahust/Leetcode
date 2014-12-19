//不能清除空格

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        if(s.empty())
            return;
        int i,j,k;
        i=0;
        j=s.length()-1;
        size_t space=0;
        while(j>=0&&s[j]==' ')
        {
            space++;
            j--;
        }
        s.erase(++j,space);
        space=0;
        while(i<(int)s.length()&&s[i]==' ')
        {
            space++;
            i++;
        }
        s.erase(0,space);
        i=0;
        j=s.length()-1;
        while(i<j)
        {
            swap(&s[i],&s[j]);
            i++;
            j--;
        }
        i=j=0;
        while(i<(int)s.length())
        {
            while(j<(int)s.length()&&s[j]!=' ') j++;
            //k指向空格
            k=j;
            j=k-1;
            if(j<(int)s.length())
            {
                while(i<j)
                {
                    swap(&s[i],&s[j]);
                    i++;
                    j--;
                }
            }
            i=j=k+1;
        }
    }
    void swap(char *a,char *b)
    {
        char temp=*a;
        *a=*b;
        *b=temp;
    }
};

int main()
{
    Solution s;
    string ss="  the sky is blue  ";
    cout<<ss.length()<<endl;
    s.reverseWords(ss);
    cout<<ss.length()<<endl;
    cout<<ss<<endl;
}

