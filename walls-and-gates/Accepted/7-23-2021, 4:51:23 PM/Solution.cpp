// https://leetcode.com/problems/walls-and-gates

class Solution {
public:
    const int WALL = -1;
    const int EMPTY = 2147483647;
    const int GATE = 0;
    
    int dx[4] ={-1,1,0,0};
    int dy[4] ={0,0,1,-1};
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        
        queue < pair <int ,int> > q;
        
        // push all gates in queue and we will do a bfs from these gates
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(rooms[i][j] == GATE){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while(!q.empty()){
             pair <int ,int> val = q.front();
             q.pop();
            
            int r = val.first;
            int c = val.second ;
            
             for(int i =0 ;i<4;i++){
                 int nr = r+ dx[i];
                 int nc = c+dy[i];
                 
                 if(nr <0 || nr >= n || nc <0 || nc >=m || rooms[nr][nc] == WALL || rooms[nr][nc] <=rooms[r][c]+1)
                     continue;
                     else
                 {
                     rooms[nr][nc] = rooms[r][c]+1;
                     q.push(make_pair(nr,nc));
                 }
                 
             }
            
            
        }
        return ;
        
        
        
    }
};