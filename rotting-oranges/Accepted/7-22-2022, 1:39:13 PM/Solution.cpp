// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n  = grid.size();
        int m = grid[0].size();
        
        
        int freshOranges =0;
        int rottenOranges =0;
        
        queue<pair<int ,int> > q;
        
        for(int i = 0 ;i< n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 1){
                    freshOranges ++;
                }
                else if(grid[i][j] == 2){
                    rottenOranges++;
                    q.push({i,j});
                }
            }
        }
        
        
        if(freshOranges ==0)
            return 0;
        if(rottenOranges == 0)
            return -1;
        
       int dx[4] ={-1,1,0,0};
        int dy[4] ={0,0,-1,1};
        int time =0 ;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                for(int i =0 ;i< 4;i++){
                    int nr = cur.first + dx[i];
                    int nc = cur.second + dy[i];
                    if(nr>=0 && nc>=0 && nr <n && nc< m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        freshOranges -- ;
                        q.push({nr,nc});
                    }
                }
            }
            time ++;
            
        }
        
       return freshOranges == 0 ? time-1 : -1 ;
        
    }
};