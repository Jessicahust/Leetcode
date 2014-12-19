#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int edit[m+1][n+1];
        int i,j;
        for(i=0;i<=m;i++)
            edit[i][0]=i;
        for(j=0;j<=n;j++)
            edit[0][j]=j;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    edit[i][j]=edit[i-1][j-1];
                else
                {
                    edit[i][j]=min(edit[i-1][j-1]+1,min(edit[i-1][j]+1,edit[i][j-1]+1));
                }
            }
        }
        return edit[m][n];
    }
};

int main()
{
    Solution s;
    string s1="eeba";
    string s2="abca";
    cout<<s.minDistance(s1,s2)<<endl;
}
