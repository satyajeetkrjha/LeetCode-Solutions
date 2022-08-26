// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3;
        vector <int> rows(n ,0);
        vector <int> cols(n,0);
        int diagonal = 0 ;
        int antidiagonal =0 ;
    
        int player = 1 ;
        for(auto move:moves){
            int x = move[0];int y = move[1];
            rows[x]+= player ;
            cols[y]+= player ;
            if( x == y){
                diagonal += player ;
            }
            if(x+y == n-1){
                antidiagonal += player;
            }
            
            if(abs(rows[x]) == n 
               || abs(cols[y]) == n 
               || abs(diagonal) == n 
               || abs(antidiagonal) == n
              ){
                return player == 1 ? "A":"B";
            }
            player = player*-1;
            
        }
        return moves.size() == n*n ? "Draw":"Pending";
        
        
    }
};