// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dist[n+1][m+1];
        
        for(int i =0 ;i<n ;i++){
            for(int j =0 ;j<m;j++){
                dist[i][j] = INT_MAX;
            }
        }
        
        
        deque<pair <int ,int> > q;
        q.push_back({0,0});
        dist[0][0] =0 ;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop_front();
            
            int x  = curr.first ;
            int y  = curr.second ;
            int dir = grid[x][y];
            
            for(int i =0 ;i<4;i++){
                int newx = x+ dx[i];
                int newy = y + dy[i];
                
                int val = 1;
                if(i+1 == dir){
                    val  = 0;
                }
                if( newx >= 0 && newx<n && newy >=0 && newy < m){
                     if(dist[newx][newy] > dist[x][y]+ val){
                         dist[newx][newy] = dist[x][y]+ val;
                         if(val == 1){
                             q.push_back({newx,newy});
                         }
                         else{
                             q.push_front({newx,newy});
                         }
                     }
                }
                
            }
        }
       return  dist[n-1][m-1];
    }
};