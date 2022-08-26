// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int dx[4]= {1,-1,0,0};
    int dy[4]= {0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue <pair <int ,int > > q;
        int freshorange =0 ;
        int rottenorange =0 ;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 2)
                    rottenorange ++;
                if(grid[i][j] == 1)
                    freshorange ++;
            }
        }
        
        if(rottenorange == 0)
            return -1;
        if(freshorange == 0)
            return 0 ;
        
        for(int i = 0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int timer =0;
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                pair <int ,int> cur = q.front();
                q.pop();
                for(int i =0 ;i<4;i++){
                    int nr = dx[i]+cur.first;
                    int nc = dy[i]+cur.second;
                 if(nr >=0 && nc >=0 && nr <n && nc <m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2 ;
                        freshorange --;
                        q.push({nr,nc});
                    }
            }
        }
            timer++;
        
        }
        return freshorange == 0 ? timer-1 :-1;
        
        
        
        
    }
};