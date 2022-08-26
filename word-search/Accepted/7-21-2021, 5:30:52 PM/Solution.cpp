// https://leetcode.com/problems/word-search

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index =0;
        for(int i =0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(board[i][j] == word[0] && backtrack(board ,word,i,j ,index)){
                    return true;
                }
            }
        }
        return false ;
    }
    
    bool backtrack(vector<vector<char>>& board, string word,int i ,int j ,int index){
        // step 1
        if(index >= word.size()){
            return true;
        }
        // step2
        if( i <0 || j <0 || i >= board.size() || j>= board[0].size() || board[i][j]!= word[index]){
            return false ;
        }
        // step 3;
        bool ret =false;
         char temp = board[i][j];
        board[i][j] ='#'; // marked
        
         ret = backtrack(board ,word,i-1,j,index+1) ||
             backtrack(board ,word,i+1,j,index+1)||
             backtrack(board ,word,i,j+1,index+1)||
             backtrack(board ,word,i,j-1,index+1);
         board[i][j] = temp;
        return ret ;
        
    }
    
};