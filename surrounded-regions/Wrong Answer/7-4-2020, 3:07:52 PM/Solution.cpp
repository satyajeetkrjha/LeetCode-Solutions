// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        int rows =board.size();
        if(rows ==0)
            return;
        int columns =board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(board[i][j] == 'O'  && i+1< rows && j+1<columns && i-1>=0 && j-1>=0 ){
                    dfs(board,i,j,rows,columns);
                }
            }
        }
    }
    void dfs (vector <vector <char>>&board,int i ,int j,int rows,int columns){
        if(board[i][j]=='X')
            return;
        board[i][j]='X';
        int dx[4]={1,0,-1,0};
        int dy[4] ={0,1,0,-1};
        for(int index=0;index<4;index++){
            int ndx =i+dx[index];
            int ndy =j+dx[index];
            if(ndx >0 && ndx<rows && ndy >0 && ndy<columns){
                dfs(board,ndx,ndy,rows,columns);
            }
        }
    }
};