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
    vector<Interval> merge(vector<Interval> &intervals)
    {
        if(intervals.empty())
            return vector<Interval>();
        if(intervals.size()==1)
            return intervals;
        sort(intervals.begin(),intervals.end(),Solution::mycompare);
        Interval temp=intervals[0];
        vector<Interval> ret;
        int i;
        for(i=1;i<(int)intervals.size();i++)
        {
            if(temp.end<intervals[i].start)
            {
                ret.push_back(temp);
                temp=intervals[i];
            }
            else

                temp.end=max(temp.end,intervals[i].end);
        }
        ret.push_back(temp);
        return ret;
    }
    //注意，为什么要使用static呢？因为sort不是成员函数，不能直接调用类中的成员函数需要类的对象或类来调用，也可以将比较函数定义在类的外面成为非成员函数
    //还有就是不能加入等号，因为sort是严格递增的
    static bool mycompare(const Interval &a,const Interval &b)
    {
        return a.start<b.start;
    }
};

int main()
{
    Solution s;
    Interval a1(1,3);
    Interval a2(2,6);
    Interval a3(8,10);
    Interval a4(15,18);
    vector<Interval> intervals={a4,a3,a1,a2};
    vector<Interval> result=s.merge(intervals);
    for(auto a:result)
        cout<<"[ "<<a.start<<" , "<<a.end<<" ]"<<endl;
}
