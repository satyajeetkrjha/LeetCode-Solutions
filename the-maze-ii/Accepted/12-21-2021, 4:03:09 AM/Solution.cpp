// https://leetcode.com/problems/the-maze-ii

class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n  = maze.size();
        int m = maze[0].size();
        
        
        if( n== 0 || m == 0){
            return 0;
        }
        
        int dist[n+1][m+1];
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                dist[i][j] = -1;
            }
        }
        
        queue<pair <int ,int> > q;
        q.push({start[0],start[1]});
        dist[start[0]][start[1]] = 0;
    
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

           
          
            for(int i =0 ;i<4;i++){
                
                int curr_dist = dist[curr.first][curr.second];
                 int r = curr.first ;
                 int c = curr.second;
            
                
              //  cout <<"here ...."<< curr_dist << endl;
                while(r+ dx[i] >=0 && c+ dy[i]>=0 && r + dx[i]<n && c+ dy[i] <m  && maze[r+dx[i]][c+dy[i]]!=1){
                   r +=dx[i];
                   c +=dy[i];
                   curr_dist ++;
                }
               // cout <<"r and c .."<< r << " "<< c << endl;
               // cout <<"curr_dist is "<< curr_dist << endl;
                
                if( dist[r][c] == -1 || (curr_dist < dist[r][c])){
                    dist[r][c] = curr_dist ;
                    q.push({r,c});
                }
                
            }
            
        }
        return dist [destination[0]][destination[1]];
        
        
        
        
        
    }
};