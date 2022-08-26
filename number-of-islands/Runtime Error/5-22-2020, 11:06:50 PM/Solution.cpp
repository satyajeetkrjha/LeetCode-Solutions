// https://leetcode.com/problems/number-of-islands

class Solution {
   int count;
    int dx[4]={-1,0,1,0};
     int dy [4]={0,1,0,-1};
    
    
public:
    void dfs (vector<vector<char>>& grid,int r,int c,int numsRows,int numCols,vector<vector<int>>& visited ){
        visited[r][c] =1;
        for(int dir =0;dir<4;dir++){
            int nr = r+dx[dir];
            int nc =c+ dy[dir];
            if(nr >=0 && nc >=0 && nr <= numsRows-1 && nc <= numCols-1){
                 if(!visited[nr][nc] && grid[nr][nc]=='1')
                     dfs(grid,nr,nc,numsRows,numCols,visited);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
     int   r =grid.size();// number of rows
      int  m=grid[0].size(); // number of columns
       vector<vector<int> > visited(r+1,vector<int>(m+1,0));
        count=0;
        

        for(int i =0;i<r;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] =='1' && !visited[i][j]){
                    count++;
                    dfs(grid ,i,j,r,m,visited);
                }
            }
        }
        return count;
         
    }
};