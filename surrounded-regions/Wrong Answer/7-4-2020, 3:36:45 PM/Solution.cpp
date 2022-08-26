// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    bool boundary_check(vector<vector<char>>& board,int i ,int j){
        int rows =board.size();
        int columns =board[0].size();
        if(  i ==0  || j==0 || i ==rows-1 || j ==columns-1 )
        return false;
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int rows =board.size();
        if(rows ==0)
            return;
        int columns =board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(board[i][j] == 'O' && boundary_check(board,i,j)){
                   // cout<<"i and j are "<<i <<" "<<j<<endl;
                    dfs(board,i,j,rows,columns);
                }
            }
        }
    }
    void dfs (vector <vector <char>>&board,int i ,int j,int rows,int columns){
        if(board[i][j]=='X')
            return;
        if(boundary_check(board,i,j)){
            board[i][j]='X';
        //cout<<"i and j marked are "<<i<<" "<<j<<endl;
        int dx[4]={1,0,-1,0};
        int dy[4] ={0,1,0,-1};
        for(int index=0;index<4;index++){
            int ndx =i+dx[index];
            int ndy =j+dx[index];
            if(ndx >=0 && ndx<rows && ndy >=0 && ndy<columns){
                dfs(board,ndx,ndy,rows,columns);
            }
        }
    }
    }
};