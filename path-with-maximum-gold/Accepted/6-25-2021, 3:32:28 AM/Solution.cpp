// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:
     int visited[100][100];
    int dfs (vector<vector<int>>& grid,int r,int c,int n,int m){
         if( r>=n || c>=m || r <0 || c<0){
             return 0;
         }
         if(visited[r][c] ==1 || grid[r][c] ==0){
            return 0;   
         }
        visited[r][c] =1;
        int gold = grid[r][c];
        int left = dfs(grid,r-1,c,n,m);
        int right = dfs(grid,r+1,c,n,m);
        int top = dfs(grid,r,c+1,n,m);
        int bottom = dfs(grid,r,c-1,n,m);
        visited[r][c] =0;
        int temp =max({left,right,top,bottom});
        return gold+temp;
        
        
    }
        
        
    int getMaximumGold(vector<vector<int>>& grid) {
       int r = grid.size();
       int c = grid[0].size();
       int maxgold =0;
        
       memset(visited,0,sizeof(visited));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               int gold = dfs(grid,i,j,r,c);
                maxgold = max(maxgold,gold);
            }
        }
        return maxgold;
        
    }
};