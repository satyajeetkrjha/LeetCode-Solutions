// https://leetcode.com/problems/walls-and-gates

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
     
        const int INF = 2147483647;
        int n = rooms.size();
        int m = rooms[0].size();
        queue <pair <int ,int> > q;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j< m;j++){
                if(rooms[i][j] ==0)
                    q.push({i,j});
            }
        }
        
        int dx[4] ={1,-1,0,0,};
        int dy[4] ={ 0,0,-1,1};
        while(!q.empty()){
            int sz = q.size();
            for(int i =0 ;i<sz;i++){
                auto cur = q.front();
                q.pop();
                for(int i =0 ;i<4;i++){
                    int nr = cur.first+dx[i];
                    int nc = cur.second +dy[i];
                    if(nr>=0 && nc>=0 && nr <n && nc <m && rooms[nr][nc] ==INF){
                        rooms[nr][nc] =rooms[cur.first][cur.second]+1;
                        q.push({nr,nc});
                    }
                }
                
            }
        }
    }
};