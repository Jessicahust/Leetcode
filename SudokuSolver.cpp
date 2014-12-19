#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char> > &board)
    {
        if(board.empty()||board[0].size()!=9||board.size()!=9)
            return ;
        helper(board,0,0);
    }
    bool helper(vector<vector<char> > &board,int row,int col)
    {
        if(col>=9)
            return helper(board,row+1,0);
        if(row==9)
            return true;
        if(board[row][col]=='.')
        {
            for(int k=1; k<=9; k++)
            {
                board[row][col]=(char)k+'0';
                if(isValid(board,row,col))
                {
                    if(helper(board,row,col+1))
                        return true;
                }
                board[row][col]='.';
            }
        }
        else
            return helper(board,row,col+1);
        return false;
    }
    bool isValid(vector<vector<char> > &board,int i,int j)
    {
        for(int k=0; k<9; k++)
        {
            if(k!=j && board[i][k]==board[i][j])
                return false;
        }
        for(int k=0; k<9; k++)
        {
            if(k!=i && board[k][j]==board[i][j])
                return false;
        }
        for(int row = i/3*3; row<i/3*3+3; row++)
        {
            for(int col=j/3*3; col<j/3*3+3; col++)
            {
                if((row!=i || col!=j) && board[row][col]==board[i][j])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > vec= {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s.solveSudoku(vec);
    for(auto a:vec)
    {
        for(auto t:a)
            cout<<t<<" ";
        cout<<endl;
    }
}
