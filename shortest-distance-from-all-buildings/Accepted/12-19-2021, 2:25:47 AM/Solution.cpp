// https://leetcode.com/problems/shortest-distance-from-all-buildings

class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int shortestDistance(vector<vector<int>>& grid) {
      int rows = grid.size();
      int columns = grid[0].size();
       
      vector<vector <int> > matrix(rows,vector <int> (columns,0));
      
      int steps =0;
      int landValue =0;
      int mindist = INT_MAX;
      
        
      for(int r =0 ;r <rows;r++){
          for(int c =0 ;c<columns ;c++){
              if(grid[r][c] == 1){
                  queue<pair<int ,int> > q;
                  q.push({r,c});
                  steps =0;
                  mindist = INT_MAX;
                  while(!q.empty()){
                  int sz = q.size();
                      steps++;
                  for(int i =0 ;i<sz;i++){
                      auto curr = q.front();
                      q.pop();
                      int x = curr.first ;
                      int y = curr.second ;
                      for(int dir =0 ; dir <4;dir++){
                         int nr = x+ dx[dir];
                          int nc = y+ dy[dir];
                          if(nr >= 0 && nc >= 0 && nr <rows && nc < columns && grid[nr][nc] == landValue){
                              grid[nr][nc]--;
                              matrix[nr][nc] += steps;
                              q.push({nr,nc});
                              mindist = min(mindist,matrix[nr][nc]);
                              
                              
                          }
                      }
                      
                  }
                    
                }
                  landValue --;
              }
          }
      }
        
        
        
        return mindist ==INT_MAX ?  -1 :mindist;
        
    }
};