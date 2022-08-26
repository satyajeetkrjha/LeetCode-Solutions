// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue <pair <int ,int> > q;
        
        for(int i =0 ;i<r;i++){
            for(int j =0 ;j<c ;j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        
        
        int dx[4] ={-1,1,0,0};
        int dy[4] ={0,0,1,-1};
        
        int maxval =0;
        cout<<"q.size() is "<<q.size() <<endl;
        while(!q.empty()){
            pair<int ,int> cur = q.front();
            q.pop();
            
            for(int i =0 ;i<4;i++){
                int nr = cur.first + dx[i];
                int nc = cur.second+ dy[i];
                cout<<"nr and nc are .."<< nr << " "<<nc <<endl;
                if( nr >=0 && nc >=0 && nr < r && nc < c && grid[nr][nc] == 0){
                    grid[nr][nc] = grid[cur.first][cur.second]+1;
                    maxval = max(maxval ,grid[nr][nc]);
                    
                }
            }
            
            
            
        }
        
        return maxval > 0 ? maxval -1:-1;
        
        
        
    }
};