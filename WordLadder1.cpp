#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        if(start.empty()||end.empty()||dict.empty())
            return 0;
        int level=1;
        int count=0;
        int curr=0;
        int i;
        queue<string> q;
        q.push(start);
        count++;
        while(!q.empty())
        {
            string tmp=q.front();
            q.pop();
            count--;
            for(i=0; i<(int)tmp.size(); i++)
            {
                char ctmp=tmp[i];
                for(char c='a'; c<='z'; c++)
                {
                    if(tmp[i]==c)
                        continue;
                    tmp[i]=c;
                    if(tmp==end)
                        return level+1;
                    if(dict.count(tmp)>0)
                    {
                        q.push(tmp);
                        curr++;
                        dict.erase(tmp);
                    }
                    tmp[i]=ctmp;
                }
            }
            if(count==0)
            {
                level++;
                count=curr;
                curr=0;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string start = "hot";
    string end = "dog";
    unordered_set<string> dict = {"hot","dog"};
    cout<<s.ladderLength(start,end,dict)<<endl;
}
