// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,-1,1};
    
    bool bfs(int val ,vector<vector<int>>& heights){
        int n = heights.size() ;
        int m = heights[0].size();
        queue <pair <int ,int> > q;
         q.push({0,0});
        int visited[n+1][m+1];
        memset(visited ,0,sizeof(visited));
         visited[0][0] = 1;
       
        while(!q.empty()){
            auto cur = q.front() ;
            q.pop();
            if(cur.first == n-1 && cur.second == m-1){
                return true ;
            }
            for(int i =0 ;i< 4 ;i++){
                int nr = dx[i]+  cur.first ;
                int nc = dy[i] + cur.second ;
                
                if(nr >=0 && nc>=0 && nr < n && nc < m && !visited[nr][nc]){
                    if(abs(heights[nr][nc] - heights[cur.first][cur.second])<=val){
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
            
        }
        return false ;
        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0 ;
        int high = 1e6 ;
         int ans =0 ;
        while(low <= high){
            int mid = (low+high)/2 ;
            if(bfs(mid,heights)){ // works fine
                high = mid -1 ;
                ans = mid ;
            }
            else {
                low = mid+1;
            }
        }
        return ans ;
    }
};