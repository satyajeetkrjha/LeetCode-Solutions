// https://leetcode.com/problems/design-tic-tac-toe

class TicTacToe {
public:
    vector <vector<int>>board;
    int n ;
    TicTacToe(int n) {
        board.resize(n,vector <int>(n,0));
        this->n = n ;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        if
            (checkCol(row,col,player) 
           || checkrow(row,col,player)
           || (row == col && checkdiagonal(player))
           || (row == n-col-1 && checkantidiagonal(player)))
               
               {
               return player;
           }
           return 0;
        
    }
           bool checkrow(int row ,int col ,int player){
               for(int i =0 ;i< n;i++){
                   if(board[row][i]!=player)
                       return false;
               }
               return true;
           }
           bool checkCol(int row ,int col ,int player){
               for(int i=0 ;i<n;i++){
                   if(board[i][col]!= player){
                       return false;
                   }
               }
               return true ;
           }
           bool checkdiagonal(int player){
               for(int i =0 ;i<n;i++){
                   if(board[i][i] != player){
                       return false;
                   }
               }
               return true;
           }
           bool checkantidiagonal(int player){
               for(int i =0 ;i<n;i++){
                   if(board[i][n-i-1]!= player){
                       return false;
                   }
               }
               return true ;
           }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */