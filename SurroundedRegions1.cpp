#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if(board.empty()||board[0].empty())
            return;
        int row=board.size();
        int col=board[0].size();
        int i,j;
        for(i=0; i<row; i++)
        {
            bfs(i,0,board);
            bfs(i,col-1,board);
        }
        for(j=0; j<col; j++)
        {
            bfs(0,j,board);
            bfs(row-1,j,board);
        }
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
    void bfs(int i,int j,vector<vector<char> > &board)
    {
        if(board[i][j]!='O')
            return;
        board[i][j]='#';
        queue<int> q;
        int line=i*board[0].size()+j;
        q.push(line);
        while(!q.empty())
        {
            line=q.front();
            q.pop();
            int row=line/board[0].size();
            int col=line%board[0].size();
            if(row>0&&board[row-1][col]=='O')
            {
                board[row-1][col]='#';
                q.push((row-1)*board[0].size()+col);
            }
            if(row<board.size()-1&&board[row+1][col]=='O')
            {
                board[row+1][col]='#';
                q.push((row+1)*board[0].size()+col);
            }
            if(col>0&&board[row][col-1]=='O')
            {
                board[row][col-1]='#';
                q.push(row*board[0].size()+col-1);
            }
            if(col<board[0].size()-1&&board[row][col+1]=='O')
            {
                board[row][col+1]='#';
                q.push(row*board[0].size()+col+1);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char> > vec={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    //vector<vector<char> > vec={{'O','O','O','O'},{'O','O','O','O'},{'O','O','O','O'},{'O','O','O','O'}};
    s.solve(vec);
    for(auto a:vec)
    {
        for(auto v:a)
            cout<<v<<" ";
        cout<<endl;
    }
}
