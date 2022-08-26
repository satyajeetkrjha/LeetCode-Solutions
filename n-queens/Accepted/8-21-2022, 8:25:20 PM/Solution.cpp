// https://leetcode.com/problems/n-queens

class Solution {
public:
    
    vector <vector<string > >  res ;
    
    bool isValid(vector<string> &board,int row ,int column){
        for(int i = row ;i>=0 ;i--){
            if(board[i][column] == 'Q')
                return false;
        }
        for(int i  = row ,j = column ;i>=0 && j>=0 ;i--,j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(int  i = row ,j= column ;i>=0 && j>=0 ;i--,j++){
            if(board[i][j] == 'Q')
                return false ;
        }
        return true ;
    }
    
    void dfs(vector <string> &board ,int row){
        if(row == board.size()){
            res.push_back(board);
            return ;
        }
        for(int i =0 ;i<board.size();i++){
            if(isValid(board,row,i)){
                board[row][i] = 'Q';
                dfs(board,row+1);
                board[row][i] ='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n<=0)
            return {{}};
        vector <string> board(n, string(n,'.'));
        dfs(board,0);
        return res ;
    }
};