#include<iostream>
#include<queue>
#include<string>
#include<unordered_set>
using namespace std;

class Solution
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		if (start.size() != end.size())
			return 0;
		if (start.empty() || end.empty())
			return 1;
		if (dict.size() == 0)
			return 0;
		int distance = 1; //!!!
		queue<string> queToPush, queToPop;
		queToPop.push(start);
		while (dict.size() > 0 && !queToPop.empty())
		{
			while (!queToPop.empty())
			{
				string str(queToPop.front()); //!!!how to initialize the str
				queToPop.pop(); //!!! should pop after it is used up
				for (int i = 0; i < str.size(); i++)
				{
					for (char j = 'a'; j <= 'z'; j++)
					{
						if (j == str[i])
							continue;
						char temp = str[i];
						str[i] = j;
						if (str == end)
							return distance + 1; //found it
						if (dict.count(str) > 0) //exists in dict
						{
							queToPush.push(str); //find all the element that is one edit away
							dict.erase(str); //delete corresponding element in dict in case of loop
						}
						str[i] = temp; //
					}
				}
			}
			cout<<queToPush.size()<<" "<<queToPop.size()<<endl;
			swap(queToPush, queToPop); //!!! how to use swap
			cout<<queToPush.size()<<" "<<queToPop.size()<<endl;
			distance++;
		} //end while
		return 0; //all the dict words are used up and we do not find dest word
	} //end function
};

int main()
{
    Solution s;
    string start = "hot";
    string end = "dog";
    unordered_set<string> dict = {"hot","dog"};
    cout<<s.ladderLength(start,end,dict)<<endl;
}
