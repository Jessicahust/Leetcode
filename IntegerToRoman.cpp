#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string str[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int i;
        string ret;
        for(i=0;num>0;i++)
        {
            while(num>=value[i])
            {
                num-=value[i];
                ret+=str[i];
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.intToRoman(3999)<<endl;
}
