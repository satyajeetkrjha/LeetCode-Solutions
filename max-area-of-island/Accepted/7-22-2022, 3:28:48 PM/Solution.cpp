// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int sum ;
    void dfs(vector<vector<int>>& grid ,int color,int r ,int c){
        if(r < 0 || c< 0 || r >=grid.size() || c >= grid[0].size() || grid[r][c]!=1)
            return ;
        grid[r][c] = color ;
        sum ++;
        dfs(grid,color,r,c+1);
        dfs(grid,color,r+1,c);
        dfs(grid,color ,r-1,c);
        dfs(grid,color,r,c-1);
        return ;
        
    }
    
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     
        int n = grid.size();
        int m = grid[0].size();
        
        
        int color = 2 ;
        int maxarea = 0;
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 1){
                    sum =0 ;
                    dfs(grid,color,i ,j);
                    maxarea = max(maxarea,sum);
                    color++;
                }
            }
        }
        return maxarea ;
        
        
    }
};