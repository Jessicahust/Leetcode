#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int map[26];
        map['I'-'A']=1;
        map['V'-'A']=5;
        map['X'-'A']=10;
        map['L'-'A']=50;
        map['C'-'A']=100;
        map['D'-'A']=500;
        map['M'-'A']=1000;
        int i;
        int res=0;
        s.push_back(s[s.length()-1]);
        for(i=0;i<s.length()-1;i++)
        {
            if(map[s[i]-'A']>=map[s[i+1]-'A'])
                res+=map[s[i]-'A'];
            else
                res-=map[s[i]-'A'];
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.romanToInt("IVVII")<<endl;
}
