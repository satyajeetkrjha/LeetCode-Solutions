// https://leetcode.com/problems/walls-and-gates


class Solution {
public:
    const int INFINITE = 2147483647;
    queue <pair <int ,int> > q;
     int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,-1,1};
   
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        queue <pair <int ,int> > q;
        int n = rooms.size();
        int m = rooms[0].size();
        
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(rooms[i][j]  == 0){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int r = cur.first ;
            int c = cur.second ;
            for(int i =0 ;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
              if(nr >=0 && nr <n && nc>=0 && nc <m && rooms[nr][nc] ==INFINITE){
                 rooms[nr][nc] = rooms[r][c]+1;
                  q.push({nr,nc});
              }
            }
        }
        return ;
        
    }
};