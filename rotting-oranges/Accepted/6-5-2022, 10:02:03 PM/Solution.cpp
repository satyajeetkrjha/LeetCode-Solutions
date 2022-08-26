// https://leetcode.com/problems/rotting-oranges


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int numfresh = 0 ;
      int numrotten =0;
      int n = grid.size();
      int m = grid[0].size();
       
      queue <pair <int ,int> > q;
        
      for(int i =0 ;i<n;i++){
          for(int j =0 ;j<m;j++){
              if(grid[i][j] == 1){
                  numfresh++;
              }
              if(grid[i][j] == 2){
                  numrotten++;
                  q.push({i,j});
              }
          }
      }
        
    //test case 4 that there are no fresh oranges so nothing gets rotten
        if(numfresh == 0){
            return 0;
        }
        
        // there are no rotten oranges so nothing gets rotten
        if(numrotten == 0){
            return -1 ;
        }
        
        
        int time =0;
        /*
        imagine a situation where there are total 10 rotten oranges and 
        only one fresh orange at level 2 .now we already marked it rotten so we don't need to process bfs at all after this from the newwly added rotten orange .Think hard
        */
        int dx[4] ={-1,1,0,0};
        int dy[4] ={0,0,-1,1};
        while(!q.empty() && numfresh >0){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front(); // this is a rotten orange
                q.pop();
               // now look at its neighbours and rot them
                for(int k =0 ;k<4;k++){
                    int nr = cur.first+dx[k];
                    int nc = cur.second+dy[k];
                    if(nr >=0 && nc>=0 && nr <grid.size() && nc <grid[0].size() && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        numfresh --;
                        q.push({nr,nc});
                    }
                }
                
            }
            time++;
        }
        
        if(numfresh == 0)
          return time ;
        return -1 ;
    }
};