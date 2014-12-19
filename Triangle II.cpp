#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        int i;
        vector<vector<int> > vec(numRows);
        for(i=0;i<numRows;i++)
           vec[i]=getRow(i);

        return vec;
    }
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
            return {1};
        vector<int> vec1(rowIndex);
        vector<int> vec2(rowIndex+1);
        vec1=getRow(rowIndex-1);
        vec2[0]=1;
        for(int i=1;i<rowIndex;i++)
        {
            vec2[i]=vec1[i-1]+vec1[i];
        }
        vec2[rowIndex]=1;
        return vec2;
    }
};

int main()
{
    Solution s;
    int n;
    cout<<"input n is :";
    cin>>n;
    vector<vector<int> > vec=s.generate(n);
    for(auto v:vec)
    {
        for(auto a:v)
            cout<<a<<" ";
        cout<<endl;
    }
    cout<<endl;
}
