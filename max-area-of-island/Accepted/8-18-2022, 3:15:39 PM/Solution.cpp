// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int maxval=0;
    
    void dfs(vector<vector<int>>& grid,int i,int j ,int &val){
        if(i <0 || j<0 || i>=grid.size() || j>=grid[0].size() ||
          grid[i][j] == 0 || grid[i][j] == 2)
            return;
        grid[i][j] = 2;
        val++;
        maxval = max(maxval,val);
        dfs(grid,i+1,j,val);
        dfs(grid,i-1,j,val);
        dfs(grid,i,j+1,val);
        dfs(grid,i,j-1,val);
    }
    
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
        int val =0;
      for(int i =0 ;i<n;i++){
          for(int j = 0 ;j<m;j++){
              if(grid[i][j] == 1){
                  val =0;
                  dfs(grid,i,j,val);
              }
          }
      }
        return maxval;
    }
};