// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:
    void dfs (vector<vector<int>>& grid ,int r ,int c ){
            if( r <0 || c <0 || r>=grid.size() || c>= grid[0].size() || grid[r][c] == 1){
                return;
            }
            grid[r][c] =1 ;
            dfs(grid ,r+1 ,c);
            dfs( grid ,r-1,c);
            dfs( grid ,r,c-1);
            dfs(grid ,r,c+1);
            
        }
    
    int closedIsland(vector<vector<int>>& grid) {
      int n  = grid.size();
      int m = grid[0].size();
        
      // there are n rows  
      for(int i =0 ;i<n;i++){
          dfs(grid ,i ,0); // (0,0),(1,0),(2,0)........
          dfs(grid ,i ,m-1); // (0 ,7),(1,7),(2,7),(3,7)..........
      }
      
        for(int i =0 ;i<m;i++){
            dfs(grid ,0 ,i); // (0,0) (0,1),......(0,7)
            dfs(grid,n-1,i);
        }
        
      
        int ans =0;
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if( grid[i][j] ==0){
                    ans ++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans ;
    
    }
};