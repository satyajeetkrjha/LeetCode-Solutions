// https://leetcode.com/problems/shortest-path-to-get-food

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        
       //[(0, -1), (0, 1), (1, 0), (-1,0)] 
       int dx[4]={0 ,0 ,1,-1};
       int dy[4]={-1,1,0,0};
       if(grid.size() == 0 || grid[0].size() ==0){
           return 0 ;
       } 
        int n = grid.size();int m = grid[0].size();
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
            for(int i =0 ;i<q.size();i++){
                auto[r,c] = q.front();q.pop();
                for(int i =0 ;i<4;i++){
                    int nr = r+ dx[i];
                    int nc = c+ dy[i];
                    
                    if( nr < 0 || nc <0 || nr >=n  || nc >= m || grid[nr][nc]=='X')
                        continue ;
                    
                    if(grid[nr][nc] == '#')
                        return steps ;
                    
                    grid[nr][nc] = 'X';
                    q.push({nr,nc});
                        
                        
                    }
                }
            }
        return -1 ;
        }
        
};