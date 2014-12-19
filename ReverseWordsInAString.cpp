#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        string tmp;
        stringstream ss(s);
        s.clear();
        int i,j;
        while(ss)
        {
            ss>>tmp;
            i=0;
            j=tmp.length()-1;
            while(i<j)
            {
                swap(&tmp[i],&tmp[j]);
                i++;
                j--;
            }
            s+=tmp+' ';
            tmp.clear();
        }
        i=0;
        j=s.length()-1;
        size_t space=0;
        while(s[j]==' ')
        {
           space++;
           j--;
        }
        s.erase(++j,space);
        j=s.length()-1;
        while(i<j)
        {
            swap(&s[i],&s[j]);
            i++;
            j--;
        }
        cout<<s<<endl;
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
    string ss="the sky is blue";
    cout<<ss.length()<<endl;
    s.reverseWords(ss);
    cout<<ss.length()<<endl;
}
