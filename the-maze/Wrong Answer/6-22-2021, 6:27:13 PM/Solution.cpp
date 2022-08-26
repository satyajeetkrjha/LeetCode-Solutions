// https://leetcode.com/problems/the-maze

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int R = maze.size();
        int C = maze[0].size();
        int visited[R+1][C+1];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                visited[i][j] = 0 ;
            }
        }
        int dx[4] ={0,0,-1,1};
        int dy[4] ={1,-1,0,0};
        queue <pair <int,int> > q;
        q.push(make_pair(start[0],start[1]));
        visited[start[0]][start[1]] = 1;
        while(!q.empty()){
            pair <int ,int> cur = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cur.first+dx[i];
                int nc = cur.second+dy[i];
                // within the reach and should not be visited and should not be a wall
                if(nr  >=0 && nr <R && nc >=0 && nc <C && maze[nr][nc] == 0 && !visited[nr][nc]){
                   if(nr == destination[0] && nc == destination[1]){
                       return true;
                   }
                    q.push(make_pair(nr,nc));
                    visited[nr][nc] =1;
                }
            }   
        }
                          return false ;
        
        
        
        
    }
};