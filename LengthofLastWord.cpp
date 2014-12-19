#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        istringstream istr(s);
        vector<string> vec;
        string ss;
        while(istr>>ss)
            vec.push_back(ss);
        if(vec.size()==0)
            return 0;
        return vec[vec.size()-1].length();
    }
};

int main()
{
    const char *s = "Hello World";
    Solution ss;
    cout<<ss.lengthOfLastWord(s)<<endl;
}
