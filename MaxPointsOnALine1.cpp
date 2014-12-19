#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<climits>
using namespace std;

struct Point
{
    int x;
    int y;
    Point():x(0),y(0) {}
    Point(int a,int b):x(a),y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		unordered_map<float,int> mp;
		int maxNum = 0;
		for(int i = 0; i < points.size(); i++)
		{
			mp.clear();
			mp[INT_MIN] = 0;
			int duplicate = 1;
			for(int j = 0; j < points.size(); j++)
			{
				if(j == i) continue;
				if(points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
				mp[k]++;
			}
			unordered_map<float, int>::iterator it = mp.begin();
			for(; it != mp.end(); it++)
				if(it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
		}
		return maxNum;
    }
};

int main()
{
    Solution s;
    vector<Point> pp= {Point(0,0),Point(0,0),Point(3,10),Point(0,2),Point(0,2),Point(3,10)};
    cout<<s.maxPoints(pp)<<endl;
}
