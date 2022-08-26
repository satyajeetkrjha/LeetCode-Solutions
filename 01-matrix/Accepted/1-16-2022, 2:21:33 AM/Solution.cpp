// https://leetcode.com/problems/01-matrix

class Solution {
public:
    
    int dx[4] ={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        vector <vector <int> > dist(r,vector<int>(c,INT_MAX));
      
        queue <pair <int ,int> > q;
        
        for(int i=0 ;i<r ;i++){
            for(int j=0 ;j<c ;j++){
                if(mat[i][j] ==0){
                    dist[i][j] =0 ; // note u are 0 so mark that dist as 0
                    q.push({i,j});
                }
            }
        }
        
        
        while(!q.empty()){
            int sz= q.size();
            for(int i =0 ;i<sz;i++){
                auto curr = q.front();
                q.pop();
                for(int dir = 0 ;dir <4;dir++){
                    int nr = curr.first + dx[dir];
                    int nc = curr.second + dy[dir];
                    if(nr >=0 && nr < r && nc >=0 && nc <c){
                        if(dist[nr][nc] > dist[curr.first][curr.second]+1){
                            dist[nr][nc] = dist[curr.first][curr.second]+1;
                            q.push({nr,nc});
                        }
                    }
                }    
                
            }
        }
        return dist ;
        
        
        
        
    }
};