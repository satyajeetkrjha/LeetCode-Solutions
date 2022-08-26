// https://leetcode.com/problems/shortest-distance-from-all-buildings

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector <int> > matrix(n,vector <int> (m,0));
        int mindist = INT_MAX;
        int steps =0;
        int landvalue =0;
        queue <pair <int ,int> > q;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 1){
                    steps =0;
                    q.push({i,j});
                    mindist =INT_MAX;
                    while(!q.empty()){
                    int sz = q.size();
                        steps ++;
                    for(int k =0 ;k<sz;k++){
                        auto cur = q.front();
                        q.pop();
                        int r = cur.first ;
                        int c = cur.second ;
                        for(int z=0 ;z<4;z++){
                            int nr = r +dx[z];
                            int nc = c+ dy[z];
                            if(nr>=0 && nc >=0 && nr <n && nc<m && grid[nr][nc] == landvalue){
                                grid[nr][nc]--;
                                matrix[nr][nc] = matrix[nr][nc]+steps ;
                                q.push({nr,nc});
                                mindist = min(mindist,matrix[nr][nc]);
                            }
                        }
                    }
                }
                     landvalue--;
            }
               
                
        }
            
        }
        return mindist == INT_MAX ? -1 :mindist;
        
    }
};