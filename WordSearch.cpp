#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty())
            return true;
        if(board.empty()||board[0].empty())
            return false;
        int row=board.size();
        int col=board[0].size();
        int i;
        int j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(word[0]==board[i][j]&&dfs(word,i,j,0,board))
                    return true;
            }
        }
        return false;
    }
    bool dfs(string word,int row,int col,int index,vector<vector<char> > &board)
    {
        if(index==(int)word.size()-1)
            return true;
        char c=board[row][col];
        board[row][col]='#';
        //up
        if(row-1>=0&&board[row-1][col]==word[index+1])
            if(dfs(word,row-1,col,index+1,board))
                return true;
        //down
        if(row+1<(int)board.size()&&board[row+1][col]==word[index+1])
            if(dfs(word,row+1,col,index+1,board))
                return true;
        //left
        if(col-1>=0&&board[row][col-1]==word[index+1])
            if(dfs(word,row,col-1,index+1,board))
                return true;
        //right
        if(col+1<(int)board[0].size()&&board[row][col+1]==word[index+1])
            if(dfs(word,row,col+1,index+1,board))
                return true;
        board[row][col]=c;
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > vec={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string str="AB";
    cout<<s.exist(vec,str)<<endl;
}
