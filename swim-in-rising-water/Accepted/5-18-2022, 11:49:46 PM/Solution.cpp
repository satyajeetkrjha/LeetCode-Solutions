// https://leetcode.com/problems/swim-in-rising-water

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int> ,vector <vector <int> > ,greater <vector <int> > > pq;
        int time =0;
        pq.push({grid[0][0],0,0});
        
        int visited[n+1][n+1];
        memset(visited ,false,sizeof(visited));
        
        int dx[4] ={1,-1,0,0};
        int dy[4] ={0,0,-1,1};
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int t = temp[0];
            int r = temp[1];
            int c = temp[2];
            time = max(time ,t);
            
            if(r == n-1 && c == n-1){
                return time ;
            }
            
            if(!visited[r][c]){
                visited[r][c] = 1;
                for(int i =0 ;i< 4;i++){
                    int nr = r + dx[i];
                    int nc = c+ dy[i];
                    if(nr>=0 && nc>=0 && nr <n && nc <n){
                        pq.push({grid[nr][nc],nr,nc});
                    }
                }
            }
            
        }
        return time ;
        
    }
};