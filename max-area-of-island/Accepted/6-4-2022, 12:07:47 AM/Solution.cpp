// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int sum =0;
    
    void dfs(vector<vector<int>>& grid ,int r ,int c ,int color){
    
     if(r <0 || c < 0 || r >= grid.size() || c >=grid[0].size() ||grid[r][c]!=1){
            return ;
        }
        sum++;
        grid[r][c] = color;
        dfs(grid,r+1,c,color);
        dfs(grid,r-1,c,color);
        dfs(grid,r,c+1,color);
        dfs(grid,r,c-1,color);
        
        
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans =INT_MIN;
        int n = grid.size();
        if(n ==0 ) return 0;
        int m= grid[0].size();
        
         int color = 2 ;
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j<m;j++){  
                sum =0;
                if(grid[i][j] == 1){
                    dfs(grid,i,j,color);
                    color++;
                }
                ans = max(ans ,sum);
            }
        }
        return ans ;
    }
};