// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,-1,1};
    vector<vector<int>> visited;
    void dfs(vector<vector<char>>& board ,int r ,int c){
        if(r<=0 || r>=board.size()-1 || c<=0 || c>=board[0].size()-1 || visited[r][c] == 1){
            return;
        }
        visited[r][c] =1 ;
        
        if(board[r][c] == 'O')
            board[r][c] = 'X';
        
        for(int i =0 ;i<4 ;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            dfs(board,nr,nc);
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        visited.resize(n,vector<int>(m,0));
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(board[i][j] == 'X'){
                    dfs(board,i,j);
                }
            }
        }
        
        
    }
};