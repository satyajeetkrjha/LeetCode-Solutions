// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    int bfs(vector <vector <int>> & grid ,int k){
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int> > visited(n,vector <int> (m,-1));
        
        queue <vector <int>> q;
        q.push({0,0,0,k}) ; // r ,c , current length , k obstacles
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur[0];
            int c = cur[1];
            int len = cur[2];
            int obstacle = cur[3];
            
            if(r < 0 || c < 0 || r >= n || c >=m){
                continue;
            }
            
            if ( r == n-1 && c == m-1){
                return len;
            }
            
            if(grid[r][c] ==1){
                if(obstacle > 0){
                    obstacle --;
                }
                else{
                    continue;
                }
            }
            if(visited[r][c]!= -1 &&  visited[r][c] >= obstacle){
                continue;
            }
            visited[r][c] = obstacle ;
            q.push({r+1,c,len+1,obstacle});
            q.push({r,c+1,len+1,obstacle});
            q.push({r-1,c,len+1,obstacle});
            q.push({r,c-1,len+1,obstacle});
            
            
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
       int ans  = bfs(grid,k);
        return ans ;
    }
};