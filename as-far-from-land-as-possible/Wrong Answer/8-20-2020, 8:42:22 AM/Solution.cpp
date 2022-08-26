// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4] ={1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
       queue <pair<int,int> > q;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
               if(grid[i][j] ==1){
                   q.push({i,j});
               }
           }
       }
        int maxDist = 0;
       while(!q.empty()){
           pair <int,int> cur = q.front();
           q.pop();
           for(int i=0;i<4;i++){
               int ndx = cur.first+dx[i];
               int ndy = cur.first+dy[i];
               if(ndx >=0 && ndx< grid.size() && ndy >=0 && ndy <grid[0].size() && grid[ndx][ndy] ==0){
                   grid[ndx][ndy] =grid[cur.first][cur.second]+1;
                   maxDist = max(maxDist,grid[ndx][ndy]);
                   q.push({ndx,ndy});
               }
           }
       } 
       return maxDist > 0 ? maxDist:-1;
    }
};