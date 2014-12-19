#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size=digits.size()-1;
        while(size>=0)
        {
            if(digits[size]<9)
            {
                digits[size]+=1;
                break;
            }
            else
            {
                digits[size]=0;
                size--;
            }
        }
        size++;
        if(size==0&&digits[size]==0)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
    void Convert(int num,vector<int> &digits)
    {
        if(num>=10)
            Convert(num/10,digits);
        digits.push_back(num%10);
    }
};

int main()
{
    vector<int> digits;
    int num;
    cin>>num;
    Solution s;
    s.Convert(num,digits);
    for(auto v:digits)
        cout<<v<<" ";
    cout<<endl;
    s.plusOne(digits);
    for(auto v:digits)
        cout<<v<<" ";
    cout<<endl;
}
