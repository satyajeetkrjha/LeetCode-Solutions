// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue <pair <int,int> > q;
        int r = grid.size();
        int c = grid[0].size();
        
       
        
        for(int i =0 ;i<r;i++){
            for(int j =0 ;j<c;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
      //  cout <<"q.size() is "<<q.size()<<endl;
        
        int dx[4] ={0,0,1,-1};
        int dy[4] ={1,-1,0,0};
        int maxval =0;
        while(!q.empty()){  
            pair <int ,int> cur = q.front();
            q.pop();
            int r = cur.first ;
            int c=  cur.second;
          //  cout <<"r and c is "<< r << " "<< c<<endl;
            for(int i =0 ;i<4;i++){
                int nr = r+ dx[i];
                int nc = c+ dy[i];
                //cout<<"nr nc "<< nr<<" "<< nc<<endl;
                if(nr >=0 && nc >=0 && nr<r && nc <c && grid[nr][nc] ==0){
                   
                    grid[nr][nc] = grid[r][c]+1;
                   //  cout <<"dist["<< nr << " ]"<<"[ "<<nc <<" ]"<<dist[nr][nc]<<endl;
                    maxval = max(maxval ,grid[nr][nc]);
                    q.push({nr,nc});
                     
                }
            }
        }
        return maxval >0 ? maxval-1:-1;
        
        
        
        
    }
};