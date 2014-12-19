#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        set<char> st;
        size_t dot=0;
        int i,j;
        for(i=0; i<9; i++)
        {
            st.clear();
            dot=0;
            for(j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                {
                    dot++;
                    continue;
                }
                st.insert(board[i][j]);
            }
            if(st.size()<9-dot)
                return false;
        }
        for(i=0; i<9; i++)
        {
            st.clear();
            dot=0;
            for(j=0; j<9; j++)
            {
                if(board[j][i]=='.')
                {
                    dot++;
                    continue;
                }
                st.insert(board[j][i]);
            }
            if(st.size()<9-dot)
                return false;
        }
        int block=0;
        for(block=0; block<9; block++)
        {
            dot=0;
            st.clear();
            for(i=block/3*3; i<block/3*3+3; i++)
            {
                for(j=block%3*3; j<block%3*3+3; j++)
                {
                    if(board[i][j]=='.')
                    {
                        dot++;
                        continue;
                    }
                    st.insert(board[i][j]);
                }
            }
            if(st.size()<9-dot)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    /*vector<vector<char> > vec= {{'8','1','4','6','5','2','7','3','9'},
        {'9','5','7','1','8','3','6','2','4'},
        {'2','3','6','9','7','4','1','5','8'},
        {'6','9','5','4','3','7','2','8','1'},
        {'4','8','1','5','2','6','3','9','7'},
        {'3','7','2','8','9','1','5','4','6'},
        {'5','6','9','3','1','8','4','7','2'},
        {'7','4','8','2','6','5','9','1','3'},
        {'1','2','3','7','4','9','8','6','5'}
    };*/
    vector<vector<char> >vec= {{'.','.','5','.','.','.','.','.','6'},
        {'.','.','.','.','1','4','.','.','.'},
        {'2','.','.','.','.','.','.','.','.'},
        {'1','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','.'},
        {'6','.','.','.','.','.','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','.','.','.','.','.'},
        {'9','.','.','.','.','.','.','.','.'},
    };
    cout<<s.isValidSudoku(vec)<<endl;
}
