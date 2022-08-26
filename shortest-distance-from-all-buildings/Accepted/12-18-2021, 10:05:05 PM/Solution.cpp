// https://leetcode.com/problems/shortest-distance-from-all-buildings

class Solution {
public:
    
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    
    int shortestDistance(vector<vector<int>>& grid) {
       
        int rows = grid.size();
        int columns = grid[0].size();
        
      
        
        vector <vector <int>> total(rows, vector <int> (columns,0));
        
        int emptylandvalue =0;
        
        
        int mindist = INT_MAX;
        for(int i =0 ;i<rows;i++){
            for(int j = 0 ;j<columns ;j++){
                if(grid[i][j] == 1){
                      queue <pair <int,int>> q;
                      q.push({i,j});
                      int steps =0;
                      mindist =INT_MAX;
                    
                    while(!q.empty()){
                         steps ++;
                        int sz = q.size();
                        for(int i =0 ;i<sz;i++){
                            auto curr = q.front();
                            q.pop();
                            for(int dir =0 ;dir <4;dir++){
                                int nr = curr.first + dx[dir];
                                int nc = curr.second + dy[dir];
                                if(nr>=0 && nc >=0 && nr < rows && nc <columns
                                   &&
                                   grid[nr][nc] == emptylandvalue
                                  ){
                                    grid[nr][nc] --;
                                    total[nr][nc]+= steps;
                                    q.push({nr,nc});
                                    mindist = min(mindist,total[nr][nc]);
                                }
                            }
                        }
                    }
                    emptylandvalue --;
                    
                }
            }
        } 
        
        return mindist == INT_MAX ? -1 :mindist;
        
        
        
        
        
    }
};