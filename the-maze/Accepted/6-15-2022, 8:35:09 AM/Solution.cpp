// https://leetcode.com/problems/the-maze

class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,-1,1};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        queue <pair <int ,int> > q;
        q.push({start[0],start[1]});
        
        int n = maze.size();
        int m = maze[0].size();
        
        int visited[n+1][m+1];
        memset(visited,0,sizeof(visited));
        visited[start[0]][start[1]] =1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur.first == destination[0] && cur.second == destination[1])
                return true ;
            
            for(int i =0 ;i< 4;i++){
                int nr =  cur.first + dx[i];
                int nc =  cur.second + dy[i];
                while(nr>=0 && nc>=0 && nr < n && nc <m && maze[nr][nc] == 0){
                    nr+= dx[i];
                    nc +=dy[i];
                }
                if(!visited[nr- dx[i]][nc-dy[i]]){
                    visited[nr-dx[i]][nc-dy[i]] =1 ;
                    q.push({nr-dx[i],nc- dy[i]});
                }   
            }
       }
     
        return false;
      }
    
};