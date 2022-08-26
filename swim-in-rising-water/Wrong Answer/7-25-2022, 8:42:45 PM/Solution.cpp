// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        priority_queue <vector<int>,vector <vector <int>>,greater <vector<int>>> pq;
        pq.push({grid[0][0],0,0,}) ;
        int visited[n+1][n+1];
        memset(visited ,false,sizeof(false));
        
        int dx[4] ={1,-1,0,0};
        int dy[4] ={0,0,-1,1};
        visited[0][0] =1 ;
        int maxTime =INT_MIN;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int weight = cur[0] ;
            maxTime = max(maxTime ,weight);
            int r = cur[1];
            int c = cur[2];
            
            if( r == n-1 && c == n-1){
                return maxTime ;
            }
            for(int i =0 ;i<4;i++){
                int nr = dx[i]+r;
                int nc = dy[i]+c ;
                if(nr >=0 && nc>=0 && nr < n && nc <n && !visited[nr][nc]){
                    visited[nr][nc] = true ;
                    pq.push({grid[nr][nc],nr,nc});
                }
            }            
        }
        return maxTime ;
    }
};