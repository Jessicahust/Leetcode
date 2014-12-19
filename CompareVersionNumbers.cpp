#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is(version1);
        istringstream iss(version2);
        vector<string> vec1;
        vector<string> vec2;
        string tmp;
        while(getline(is,tmp,'.'))
        {
            vec1.push_back(tmp);
        }
        while(getline(iss,tmp,'.'))
        {
            vec2.push_back(tmp);
        }
        int len1=vec1.size();
        int len2=vec2.size();
        int i=0,j=0;
        while(i!=len1&&j!=len2)
        {
            if(atoi(vec1[i].c_str())<atoi(vec2[i].c_str()))
                return -1;
            else if(atoi(vec1[i].c_str())>atoi(vec2[i].c_str()))
                return 1;
            i++;
            j++;
        }
        if(i==len1&&j==len2)
            return 0;
        while(i!=len1)
        {
            if(atoi(vec1[i].c_str())!=0)
                return 1;
            i++;
        }
        while(j!=len2)
        {
            if(atoi(vec2[j].c_str())!=0)
                return -1;
            j++;
        }
        return 0;
    }
};

int main()
{
    string s1="01.23.0.0";
    string s2="01.23";
    Solution s;
    cout<<s.compareVersion(s1,s2)<<endl;
}
