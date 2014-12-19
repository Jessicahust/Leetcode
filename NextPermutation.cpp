#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        if(num.empty()||num.size()==1)
            return;
        int i,j,k;
        int len=num.size();
        for(i=int(num.size()-1); i>0; i--)
        {
            if(num[i]<=num[i-1])
                continue;
            else
                break;
        }
        if(i==0)
        {
            i=0;
            k=len-1;
            while(i<k)
            {
                swap(&num[i],&num[k]);
                i++;
                k--;
            }
            return;
        }
        j=i-1;
        k=len-1;
        while(i<k)
        {
            swap(&num[i],&num[k]);
            i++;
            k--;
        }
        for(i=j+1; i<len; i++)
            if(num[i]>num[j])
                break;
        swap(&num[i],&num[j]);
    }
    void swap(int *a,int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
};

int main()
{
    Solution s;
    vector<int> vec= {3,2,1,4,5,9,8,7};
    s.nextPermutation(vec);
    for(auto a:vec)
        cout<<a<<" ";
    cout<<endl;
}
