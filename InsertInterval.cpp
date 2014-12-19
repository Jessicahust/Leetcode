#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval():start(0),end(0) {}
    Interval(int s,int e):start(s),end(e) {}
};

class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        vector<Interval> ret;
        if(intervals.empty())
        {
            ret.push_back(newInterval);
            return ret;
        }
        int flag=0;
        int i;
        for(i=0; i<(int)intervals.size(); i++)
        {
            if(newInterval.start>intervals[i].end)
            {
                ret.push_back(intervals[i]);
            }
            else if(newInterval.end<intervals[i].start)
            {
                if(flag==1)
                    ret.push_back(intervals[i]);
                else
                {
                    flag=1;
                    ret.push_back(newInterval);
                    ret.push_back(intervals[i]);
                }
            }
            else
            {
                newInterval.start=min(newInterval.start,intervals[i].start);
                newInterval.end=max(newInterval.end,intervals[i].end);
            }
        }
        if(flag==0)
            ret.push_back(newInterval);
        return ret;
    }
};

int main()
{
    Solution s;
    Interval a1(1,2);
    Interval a2(3,5);
    Interval a3(6,7);
    Interval a4(8,10);
    Interval a5(12,16);
    vector<Interval> intervals= {a1,a2,a3,a4,a5};
    Interval newInternal= {0,0};
    vector<Interval> result=s.insert(intervals,newInternal);
    for(auto a:result)
        cout<<"[ "<<a.start<<" , "<<a.end<<" ]"<<endl;
}

