// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
public:
    
     int dx[4] = {0, 0, 1, -1};
     int dy[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
     
        int n = grid.size();
        int m = grid[0].size();
        
        int dist[n+1][m+1];
        
        
       for(int i =0 ;i<n ;i++){
            for(int j =0 ;j<m;j++){
                dist[i][j] = INT_MAX;
            }
        }
        
        //memset(dist,INT_MAX,sizeof(dist));
        
        
        deque <pair <int ,int> > dq ;
        dq.push_back({0,0});
        
        dist[0][0] =0;
        
        while(!dq.empty()){
            auto cur = dq.front();
            dq.pop_front();
            
             int r = cur.first ;
             int c = cur.second;
             int dir = grid[r][c];
            
            for(int i =0 ;i< 4;i++){
                int nr = r+dx[i];
                int nc = c+ dy[i];
                
                int weight =1;
                if(i+1 == dir){
                    weight =0;
                }
                
                
               
                if(nr>=0 && nr <n && nc >=0 && nc <m){
                    if(dist[nr][nc] > dist[r][c]+weight){
                        dist[nr][nc] = dist[r][c]+ weight;
                        if(weight == 1){
                            dq.push_back({nr,nc});
                        }
                         else{
                             dq.push_front({nr,nc});
                         }
                    }             
                }
            }
        }
        return dist[n-1][m-1];
        

    }
};