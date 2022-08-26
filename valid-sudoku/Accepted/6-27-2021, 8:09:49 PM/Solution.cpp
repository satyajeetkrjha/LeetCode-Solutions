// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValid(vector<vector<char>>& board ,int r ,int c,char num){
        int n = board.size();
        int m = board[0].size();
        
        for(int i =0;i<m;i++){
            if(i == c) continue;
            if(board[r][i] == num ){
                return false;
            }
        }
        
        for(int i =0;i<n;i++){
            if(i == r) continue;
            if(board[i][c] == num){
                return false;
            }
        }
        
        int start_row = r - r %3 ;
        int start_column = c - c%3;
        
        for(int i=0;i<3;i++){
            for(int j =0;j<3;j++){
                if(i+start_row == r && j+start_column == c){
                    continue;
                }
                if(board[start_row+i][start_column+j] == num){
                    return false;
                }
            }
        }
        return true ;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
    
        for(int i=0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    char num = board[i][j];
                     if(isValid(board,i,j,num))
                        continue;
                      else
                        return false;
                }
            }
        }
        return true;
    }
};