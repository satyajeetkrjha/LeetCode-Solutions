// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    
    
    int dx [8] ={-1,-1,1,1,-1,0,0,1};
      int dy[8] = {-1,1,-1,1,0,1,-1,0};
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n+1][m+1];
        
        queue <pair <int,int> > q ;
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)
            return -1;
        q.push({0,0});
        int dist[n+1][m+1] ;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j< m;j++){
                dist[i][j] =INT_MAX;
                visited[i][j] =0;
            }
        }
        dist[0][0] =1 ;
        visited[0][0] = 1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first ;
            int c = cur.second ;
            
            for(int i =0 ;i<8;i++){
                int nr = cur.first +dx[i];
                int nc = cur.second+dy[i];
                
                
              
                 // neighbour is a good place
                if(nr>=0 && nr< grid.size() && nc>=0 && nc<grid[0].size() && !visited[nr][nc] && grid[nr][nc] ==0 && (dist[nr][nc] >dist[r][c]+1)){ 
                   dist[nr][nc] = dist[r][c]+1;
                    q.push({nr,nc});
                    visited[nr][nc] =1 ;
                }
            }
        }
        
        return dist[n-1][m-1] == INT_MAX  ? -1 : dist[n-1][m-1];
        
        
        
        
        
    }
};