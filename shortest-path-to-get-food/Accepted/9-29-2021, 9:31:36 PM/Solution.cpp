// https://leetcode.com/problems/shortest-path-to-get-food

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        
       //[(0, -1), (0, 1), (1, 0), (-1,0)] 
       int dx[4]={0 ,0 ,-1,1};
       int dy[4]={1,-1,0,0};
       if(grid.size() == 0 || grid[0].size() ==0){
           return 0 ;
       } 
        int n = grid.size();
        int m = grid[0].size();
        queue <pair <int ,int> > q;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == '*'){
                    q.push({i,j});
                    break;
                }
            }
        }
        
        int steps = 0 ;
        while(!q.empty()){
            steps ++ ;
            int sz = q.size(); // calculate this first
            for(int i =0 ;i<sz;i++){
                auto[r,c] = q.front();q.pop();
                for(int k =0 ;k<4;k++){
                    int nr = r+ dx[k];
                    int nc = c+ dy[k];
                    
                    if( nr < 0 || nc <0 || nr >=n  || nc >= m || grid[nr][nc]=='X')
                        continue ;
                    
                    if(grid[nr][nc] == '#') // food found 
                        return steps ;
                    
                    grid[nr][nc] = 'X'; // to mark visited
                    q.push({nr,nc});
                        
                        
                    }
                }
            }
        return -1 ;
        }
        
};