// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int sum =0;
   
    void dfs(vector<vector<int>>& grid,int r ,int c,int n,int m,vector<vector<bool>> &visited){
        if(  r<0 || r>=n || c<0 || c>=m || grid[r][c]==0 || visited[r][c])
            return ;
        sum++;
        visited[r][c]=true;
        dfs(grid,r+1,c,n,m,visited);
        dfs(grid,r-1,c,n,m,visited);
        dfs(grid,r,c+1,n,m,visited);
        dfs(grid,r,c-1,n,m,visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans =0;
        int n = grid.size();
        if( n== 0)
            return ans;
        int m =grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
       
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    sum =0;
                    dfs(grid,i,j,n,m,visited);
                    ans =max(ans,sum);
                    
                }
            }
        }
        return ans;
        
    }
};