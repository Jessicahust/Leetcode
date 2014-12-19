#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(strlen(haystack)<strlen(needle))
            return -1;
        size_t i,j,k;
        for(i=0;i<=(strlen(haystack)-strlen(needle));i++)
        {
            k=i;
            for(j=0;j<strlen(needle);j++)
            {
                if(haystack[k]==needle[j])
                    k++;
                else
                    break;
            }
            if(j==strlen(needle))
                return i;
        }
        if(j==strlen(needle))
            return i;
        return -1;
    }
};

int main()
{
    Solution s;
    char s1[]="swwssswsss";
    char s2[]="sss";
    cout<<s.strStr(s1,s2)<<endl;
}
