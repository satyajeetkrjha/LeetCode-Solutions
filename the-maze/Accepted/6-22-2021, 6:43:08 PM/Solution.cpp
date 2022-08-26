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
            if(cur.first == destination[0] && cur.second == destination[1]){
                return true ;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cur.first+dx[i];
                int nc = cur.second+dy[i];
                
                while( nr >=0 && nr< R && nc >=0 && nc< C && maze[nr][nc] ==0 ){
                    nr +=dx[i];
                    nc+=dy[i];
                }
                // if we move out it means we have hit a wall
                if(!visited[nr -dx[i]][nc-dy[i]]){
                    q.push(make_pair(nr-dx[i],nc-dy[i]));
                    visited[nr-dx[i]][nc-dy[i]]=1;
                } 
            }
        }
        return false ;
    }
};