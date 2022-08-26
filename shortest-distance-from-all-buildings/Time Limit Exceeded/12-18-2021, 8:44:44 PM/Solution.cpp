// https://leetcode.com/problems/shortest-distance-from-all-buildings

class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int bfs(vector<vector<int>>& grid ,int x,int y,int totalHouses){
    
        queue <pair <int,int> > q;
        q.push({x,y});
        
        int d =0;
        int steps =0;
        
        int rows = grid.size();
        int columns = grid[0].size();
        
        vector <vector <bool>> visited(rows,vector<bool>(columns,false));
        visited[x][y] = true;
        
        int housesReached =0;
        
        while(!q.empty() && housesReached!= totalHouses) {
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                pair <int ,int> pr = q.front();
                int r = pr.first;
                int c = pr.second;
                q.pop();
                if(grid[r][c] ==1){
                    d+= steps ;
                    housesReached ++;
                    continue;
                    
                }
                for(int i =0;i<4;i++){
                    int nr = r + dx[i];
                    int nc = c+  dy[i];
                    if(nr >= 0 && nc >=0 && nr < rows && nc <columns){
                        if(!visited[nr][nc] && grid[nr][nc]!=2){
                            visited[nr][nc] =true;
                            q.push({nr,nc});
                        }
                    }
                }
                  
                
            }
            steps ++;
        }
        
        if(housesReached != totalHouses){
            for(int i =0 ;i<rows;i++){
                for(int j =0 ;j < columns ;j++){
                    if(grid[i][j] ==0 && visited[i][j] ==1){
                        grid[i][j] =2;
                    }
                }
            }
            return INT_MAX;
        }
        return d;
        
    }
    
    
    
    int shortestDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int totalHouses = 0;
        for(int i =0 ;i<r ;i++){
            for(int j =0 ;j<c;j++){
                if(grid[i][j] == 1){
                    totalHouses ++;
                }
            }
        }
        
        
        int ans =INT_MAX;
        for(int i =0 ;i<r ;i++){
            for(int j =0 ;j<c ;j++){
                if(grid[i][j] == 0){
                    ans = min(ans,bfs(grid,i,j,totalHouses));
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans ;
        
        
        
        
        
        
    }
};