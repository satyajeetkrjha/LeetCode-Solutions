// https://leetcode.com/problems/game-of-life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        
        int dx[8] ={-1,-1,-1,0,0,1,1,1};
        int dy[8] ={-1,0,1,-1,1,-1,0,1};
        
        
        
        for(int i =0;i<rows;i++){
            for(int j =0;j<columns;j++){
                int livecells =0;
                for(int k=0;k<8;k++){
                    int nr = i+dx[k];
                    int nc = j+dy[k];
                    if(nr >=0 && nr <rows && nc>=0 && nc <columns && abs(board[nr][nc]) == 1){
                        livecells++;
                    }
                }
                
                if(board[i][j] == 1 && (livecells  >3 || livecells <2)){
                    board[i][j] = -1;
                }
                if(board[i][j] == 0 && livecells ==3){
                    board[i][j] =2;
                }
            }
        }
        
        for(int i =0;i<rows;i++){
            for(int j=0;j<columns ;j++){
                if(board[i][j] >0){
                    board[i][j] =1;
                }
                else {
                    board[i][j] =0;
                }
            }
        }
        
    }
};