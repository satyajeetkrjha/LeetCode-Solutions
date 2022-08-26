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
        for(int i=1;i<rows-1;i++){
            for(int j=1;j<columns-1;j++){
                if(board[i][j] == 'O' && boundary_check(board,i,j)){
                  cout<<"i and j are "<<i <<" "<<j<<endl;
                    dfs(board,i,j,rows,columns);
                }
            }
        }
    }
    void dfs (vector <vector <char>>&board,int i ,int j,int rows,int columns){
        if(board[i][j]=='X')
            return;
        int dx[4]={0,-1,0,1};
        int dy[4] ={-1,0,1,0};
        for(int index=0;index<4;index++){
            int ndx =i+dx[index];
            int ndy =j+dy[index];
            cout<<"ndx and ndy are"<<ndx<<" "<<ndy<<endl;
             bool val =boundary_check(board,ndx,ndy);
            cout<<"val is for ndx and ndy "<<val<<" "<<ndx<<" "<<ndy<<endl;
             if(boundary_check(board,i,j)==true && boundary_check(board,ndx,ndy) ==true){
                 board[i][j]='X';
                 cout<<"marked are and index is "<<i<<" "<<j<<endl;
                 cout<<"ndx and ndy are "<<ndx<<" "<<ndy<<endl;
             }
            if(ndx >0 && ndx<rows-1 && ndy >0 && ndy<columns-1){
                dfs(board,ndx,ndy,rows,columns);
            }
        }
    }
};