#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
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
    vector<int> vec=s.getRow(n);
    for(auto v:vec)
        cout<<v<<" ";
    cout<<endl;
}

