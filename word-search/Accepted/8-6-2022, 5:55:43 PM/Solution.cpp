// https://leetcode.com/problems/word-search

class Solution {
public:
    
    bool backtrack(vector<vector<char>>& board,int r ,int c,string word,int index){
        if(index>=word.size()){
            return true;
        } 
        if(r <0 || c<0 || r>=board.size() || c>= board[0].size() || 
           board[r][c]!=word[index])
            return false ;
        bool res = false ;
        auto temp = board[r][c];
        board[r][c] = '#';
        res = backtrack(board,r+1,c,word,index+1) ||
             backtrack(board,r-1,c,word,index+1) ||
             backtrack(board,r,c+1,word,index+1) ||
             backtrack(board,r,c-1,word,index+1);
        board[r][c] = temp;
        return res ;
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                int index = 0;
                if(board[i][j] == word[0] && backtrack(board,i,j,word,index)){
                    return true;
                }
            }
        }
        return false ;
    }
};