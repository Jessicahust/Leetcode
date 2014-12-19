#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int lens=S.length();
        int lent=T.length();
        int tcnt[256]={0};
        int fcnt[256]={0};
        int i,start;
        int found=0;
        int winStart=-1,winEnd=lens;
        for(i=0;i<lent;i++)
            tcnt[T[i]]++;
        for(i=0,start=0;i<lens;i++)
        {
            if(tcnt[S[i]]!=0)
            {
                fcnt[S[i]]++;
                if(fcnt[S[i]]<=tcnt[S[i]])
                    found++;
                if(found==lent)
                {
                    //找到一个窗口之后调整start的位置
                    while(tcnt[S[start]]==0||fcnt[S[start]]>tcnt[S[start]])
                    {
                        if(tcnt[S[start]])
                            fcnt[S[start]]--;
                        start++;
                    }
                    if(i-start<winEnd-winStart)
                    {
                        winStart=start;
                        winEnd=i;
                    }
                    fcnt[S[start]]--;
                    start++;
                    found--;
                }
            }
        }
        return winStart==-1?"":S.substr(winStart,winEnd-winStart+1);
    }
};

int main()
{
    Solution s;
    string S="SADOBECODEBANC";
    string T="ABC";
    cout<<s.minWindow(S,T)<<endl;
}
