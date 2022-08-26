// https://leetcode.com/problems/n-queens

class Solution {
public:
    vector< vector<string> > ans ;
    bool is_valid(vector <string> baord,int row,int column){
        // we will check column ,left diagonal and right diagonal but not row because we always place in a new row 
        
        // first column check so if you  place at some row and theck for all columns
        for(int i = row ;i>=0;i--){
            if(board[i][column] == 'Q'){
                return false;
            }
        }
        // check left diagonal before the specific row 
        
        for(int i = row ,j= column; i>=0 && j>=0 ;i--,j--){
            if(board[i][j] =='Q'){
                return false;
            }
        }
        
        //check right diagonal before the specific row 
        
        for(int i =row,j=column ;i>=0 && j<board.size() ;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true ;
    }
    
    
    void dfs (vector <string> &board,int row){
        if( row == board.size()){
            ans.push_back(board);
            return ;
        }
        for(int i =0; i<board.size();i++){
            if(is_valid(board,row,i)){
                board[row][i] ='Q';
                dfs(board,row+1);
                board[row][i] ='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
       if(n<=0 )
           return {{}};
        vector <string > board(n ,string(n,'.'));// create a board and mark all empty
        dfs(board,0);
        return ans ;
        
    }
};