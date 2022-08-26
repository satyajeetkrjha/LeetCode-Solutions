// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int dx[4] ={0 ,0 ,1,-1};
    int dy[4] ={1,-1,0,0};
    void dfs(vector< vector <char>> & grid ,int r ,int c,int n ,int m){
        grid[r][c]='2';
        for(int i =0 ;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            if( nr>=0 && nc>=0 && nr <n && nc<m && grid[nr][nc] =='1'){
                dfs(grid,nr,nc,n,m);
            }
        }   
    }
    
    int numIslands(vector<vector<char>>& grid) {
      
        int n = grid.size();
        int m = grid[0].size();
        
        int count =0 ;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] =='1'){
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count ;   
    }
};