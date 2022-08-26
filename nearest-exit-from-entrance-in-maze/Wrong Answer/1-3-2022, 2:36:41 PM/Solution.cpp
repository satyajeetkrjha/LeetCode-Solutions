// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
     int dx[4] ={1,-1,0,0};
     int dy[4] ={0,0,1,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       
        queue<pair<int ,int> > q ;
        q.push({entrance[0],entrance[1]});
    
        int n = maze.size();
        int m = maze[0].size();
        
        int moves =1;
        maze[entrance[0]][entrance[1]] ='+';
        
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0 ;k< sz;k++){
                auto cur = q.front(); q.pop();
               int r = cur.first ;
               int c = cur.second ;
               for(int i =0 ;i<4;i++){
                    int nr = r+ dx[i];
                    int nc = c+ dy[i] ;
                  if(nr < 0 || nr >= n || nc < 0 || nc >= m || maze[nr][nc] == '+')                   {
                    continue;
                }
        if(nr == 0 || nr == n-1 || nc == 0 || nc == m-1){
            if(maze[nr][nc] =='.')
            return moves ;
        }
                    q.push({nr,nc});
                   maze[nr][nc]='+';
            }
                moves ++;   
        }        
   }
        
       return -1;     
        
        
    }
};