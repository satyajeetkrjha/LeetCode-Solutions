// https://leetcode.com/problems/path-with-maximum-gold

class Solution {
public:
     int visited[100][100];
    void dfs (vector<vector<int>>& grid ,int &maxsum ,int r,int c){
        if(visited[r][c] ==1)
            return;
         visited[r][c] =1;
        int n = grid.size();
        int m = grid[0].size();
        maxsum = max(maxsum ,maxsum+grid[r][c]);
        cout<<"r and c "<<r<<" "<<c<<endl;
        cout<<"maxsum is "<<maxsum <<endl;
        if(r+1 >=0 && r+1<n && c>=0 && c<m && !visited[r+1][c] && grid[r+1][c]>0){
            dfs(grid,maxsum,r+1,c);
        }
         if(r-1 >=0 && c>=0 && r-1<n && c <m &&  !visited[r-1][c] && grid[r-1][c]>0){
            dfs(grid,maxsum,r-1,c);
        }
        if(r >=0 && c+1>=0 && r<n && c+1<m && !visited[r][c+1] && grid[r][c+1]>0){
            dfs(grid,maxsum,r,c+1);
        }
        
        if(r >=0 && c-1>=0 && r<n && c-1<m && !visited[r][c-1] && grid[r][c-1]>0){
            dfs(grid,maxsum,r,c-1);
        }
         visited[r][c]=0;
    
    }
        
        
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxsum =0;
        int x =-1;int y=-1;
        int visited[r+1][c+1];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]>0){
                    visited[i][j] =0;
                    x =i;
                    y=j;
                   
                }
            }
        }
        
        dfs(grid,maxsum,x,y);
        return maxsum;
        
    }
};