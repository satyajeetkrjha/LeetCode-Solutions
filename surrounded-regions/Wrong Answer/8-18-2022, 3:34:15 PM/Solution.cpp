// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    
    void dfs(vector<vector<char>>& board,int r,int c){
        int n = board.size();
        int m = board[0].size();
        if(r<=0 || c<=0 || r>=n-1 || c>=m-1 || board[r][c] == 'X'){
            return;
        }
        board[r][c] = 'X';
        dfs(board,r+1,c);
        dfs(board,r-1,c);
        dfs(board,r,c+1);
        dfs(board,r,c-1);
    }
    
    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i =1 ;i<n-2;i++){
            for(int j =1 ;j<m-2;j++){
                if(board[i][j] == 'O'){
                    dfs(board,i,j);
                }
            }
        }
    }
};