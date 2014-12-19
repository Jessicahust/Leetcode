#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int size1=a.size()-1;
        int size2=b.size()-1;
        int size=max(size1,size2);
        string digits(size+1,'0');
        while(size1>=0&&size2>=0)
        {
            if((a[size1]=='1')&&(b[size2]=='1'))
            {
                digits[size-1]='1';
                if(size1==0&&size2==0)
                    digits.insert(digits.begin(),'1');
                size1--;
                size2--;
                size--;
            }
            else if(((a[size1]=='1')||(b[size2]=='1'))&&(digits[size]=='0'))
            {
                digits[size]='1';
                size1--;
                size2--;
                size--;
            }
            else if(((a[size1]=='1')||(b[size2]=='1'))&&(digits[size]=='1'))
            {
                digits[size]='0';
                digits[size-1]='1';
                if(size1==0&&size2==0)
                    digits.insert(digits.begin(),'1');
                size1--;
                size2--;
                size--;
            }
            else
            {
                digits[size]=digits[size];
                size1--;
                size2--;
                size--;
            }
        }
        cout<<digits<<endl;
        if(size1>=0)
        {
            while(size1>=0&&size>=0)
            {
                if((digits[size]=='1')&&(a[size1]=='1'))
                {
                    digits[size]='0';
                    digits[size-1]='1';
                    if(size==0)
                        digits.insert(digits.begin(),'1');
                    size1--;
                    size--;
                }
                else if((digits[size]=='1')&&(a[size1]=='0'))
                {
                    size1--;
                    size--;
                }
                else
                {
                    digits[size]=a[size1];
                    size--;
                    size1--;
                }
            }
        }
        if(size2>=0)
        {
            while(size2>=0&&size>=0)
            {
                if((digits[size]=='1')&&(b[size2]=='1'))
                {
                    digits[size]='0';
                    digits[size-1]='1';
                    //最前面两个数相加需要进位的时候，在前面插入1
                    if(size==0)
                        digits.insert(digits.begin(),'1');
                    size2--;
                    size--;
                }
                else if((digits[size]=='1')&&(b[size2]=='0'))
                {
                    size2--;
                    size--;
                }
                else
                {
                    digits[size]=b[size2];
                    size--;
                    size2--;
                }
            }
        }
        return digits;
    }
};
int main()
{
    string b="100";
    string a="110010";
    Solution s;
    cout<<"digits: "<<s.addBinary(a,b)<<endl;
}
