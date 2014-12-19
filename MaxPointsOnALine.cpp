#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

struct Point
{
    int x;
    int y;
    Point():x(0),y(0) {}
    Point(int a,int b):x(a),y(b) {}
};
struct Line
{
    double k;
    double t;
    Line(double a,double b):k(a),t(b) {}
};
bool operator==(const Point &a,const Point &b)
{
    return a.x==b.x&&a.y==b.y;
}
bool operator<(const Point &a,const Point &b)
{
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool operator==(const Line &a,const Line &b)
{
    return a.k==b.k&&a.t==b.t;
}
bool operator<(const Line &a,const Line &b)
{
    return a.k==b.k?a.t<b.t:a.k<b.k;
}
class Solution
{
public:
    int maxPoints(vector<Point> &points)
    {
        if(points.empty()||points.size()==1)
            return points.size();
        map<Line,set<Point> > mp;
        int i,j;
        int count=0;
        for(i=0; i<(int)points.size()-1; i++)
        {
            for(j=i+1; j<(int)points.size(); j++)
            {
                Point x=points[i];
                Point y=points[j];
                double k;
                double t;
                if(x.x==y.x)
                {
                    k=1e20;
                    t=x.x;
                }
                else
                {
                    k=(y.y-x.y)/(y.x-x.x);
                    t=x.y-x.x*k;
                }
                mp[{k,t}].insert(x);
                mp[{k,t}].insert(y);
            }
        }
        auto start=mp.begin();
        while(start!=mp.end())
        {
            cout<<start->first.k<<" "<<start->first.t<<" "<<start->second.size()<<endl;
            set<Point> st=start->second;
            multiset<Point> mul(points.begin(),points.end());
            auto it=st.begin();
            int dup=0;
            while(it!=st.end())
            {
                dup+=mul.count(*it)-1;
                it++;
            }
            if(count<(int)st.size()+dup)
                count=st.size()+dup;
            start++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<Point> pp= {Point(0,0),Point(0,0),Point(3,10),Point(0,2),Point(0,2),Point(3,10)};
    cout<<s.maxPoints(pp)<<endl;
}
