#include<iostream>
#include<cctype>
#include<climits>
using namespace std;

class Solution
{
public:
     int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ret = 0;

        const char *p = str;

        while(*p == ' ') p++;

        bool valid = true;
        while(valid && *p == '+') {
            valid = false;
            p++;
        }

        while(*p == '0') p++;

        bool minus = false;
        if(*p == '-'){
            minus = true;
            p++;
        }

        while(*p != '/0'){
            if(*p >= '0' && *p <='9'){
                ret = ret * 10 + *p - '0';
                if(!minus && ret > INT_MAX) return INT_MAX; // positive and overflow
                if(minus && -ret < INT_MIN) return INT_MIN; // negative and overflow
                p++;
            } else {        // no digit then break
                break;
            }
        }

        return minus ? -ret : ret;
    }
};

int main()
{
    const char *str="  9223372036854775809";
    Solution s;
    cout<<s.atoi(str)<<endl;
}
