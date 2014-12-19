#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty()||board[0].empty())
            return;
        int row=board.size();
        int col=board[0].size();
        int i,j;
        for(i=1;i<row-1;i++)
        {
            dfs(i,0,board);
            dfs(i,col-1,board);
        }
        for(j=0;j<col;j++)
        {
            dfs(0,j,board);
            dfs(row-1,j,board);
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    void dfs(int row,int col,vector<vector<char> > &board)
    {
        if(row<0||row>=(int)board.size()||col<0||col>=(int)board[0].size())
            return;
        if(board[row][col]!='O')
            return;
        board[row][col]='#';
        dfs(row-1,col,board);
        dfs(row+1,col,board);
        dfs(row,col-1,board);
        dfs(row,col+1,board);
    }
};

int main()
{
    Solution s;
    //vector<vector<char> > vec={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    vector<vector<char> > vec={{'O','O','O','O'},{'O','O','O','O'},{'O','O','O','O'},{'O','O','O','O'}};
    s.solve(vec);
    for(auto a:vec)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
