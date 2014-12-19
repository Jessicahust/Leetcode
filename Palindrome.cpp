#include<iostream>
#include<cctype>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(isalnum(s[i])&&isalnum(s[j]))
            {
                if(isalpha(s[i]))
                    s[i]=tolower(s[i]);
                if(isalpha(s[j]))
                    s[j]=tolower(s[j]);
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                    break;
            }
            else if(isalnum(s[i]))
            {
                j--;
            }
            else if(isalnum(s[j]))
            {
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        if(i>j)
            return true;
        else
            return false;
    }
};

int main()
{
    string s="A man, a plan, a canal: Panama";
    Solution ss;
    if(ss.isPalindrome(s))
        cout<<" s is a palindrome."<<endl;
    else
        cout<<" s is not a palindrome."<<endl;
}
