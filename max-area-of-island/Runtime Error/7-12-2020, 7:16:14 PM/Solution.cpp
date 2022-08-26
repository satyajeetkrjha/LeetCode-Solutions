// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int sum =0;
    int visited[51][51];
    void dfs(vector<vector<int>>& grid,int r ,int c,int n,int m){
        if(visited[r][c] || r<0 || r>=n || c<0 || c>=m || grid[r][c]==0)
            return ;
        sum++;
        visited[r][c]=1;
        dfs(grid,r+1,c,n,m);
        dfs(grid,r-1,c,n,m);
        dfs(grid,r,c+1,n,m);
        dfs(grid,r,c-1,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans =0;
        int n = grid.size();
        if( n== 0)
            return ans;
        int m =grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    sum =0;
                    dfs(grid,i,j,n,m);
                    ans =max(ans,sum);
                    
                }
            }
        }
        return ans;
        
    }
};