#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> operand;
        int operand1;
        int operand2;
        if(tokens.empty())
            return 0;
        int i;
        for(i=0; i<(int)tokens.size(); i++)
        {
            if(tokens[i]=="+")
            {
                if(!operand.empty())
                {
                    operand1=operand.top();
                    operand.pop();
                }
                if(!operand.empty())
                {
                    operand2=operand.top();
                    operand.pop();
                }
                operand2+=operand1;
                operand.push(operand2);
            }
            else if(tokens[i]=="-")
            {
                if(!operand.empty())
                {
                    operand1=operand.top();
                    operand.pop();
                }
                if(!operand.empty())
                {
                    operand2=operand.top();
                    operand.pop();
                }
                operand2-=operand1;
                operand.push(operand2);
            }
            else if(tokens[i]=="*")
             {
                if(!operand.empty())
                {
                    operand1=operand.top();
                    operand.pop();
                }
                if(!operand.empty())
                {
                    operand2=operand.top();
                    operand.pop();
                }
                operand2*=operand1;
                operand.push(operand2);
            }
            else if(tokens[i]=="/")
             {
                if(!operand.empty())
                {
                    operand1=operand.top();
                    operand.pop();
                }
                if(!operand.empty())
                {
                    operand2=operand.top();
                    operand.pop();
                }
                operand2/=operand1;
                operand.push(operand2);
            }
            else
            {
                operand1=atoi(tokens[i].c_str());
                operand.push(operand1);
            }
        }
        return operand.top();
    }
};

int main()
{
    Solution s;
    vector<string> vec={"4","13","5","/","+"};
    cout<<s.evalRPN(vec)<<endl;
}
