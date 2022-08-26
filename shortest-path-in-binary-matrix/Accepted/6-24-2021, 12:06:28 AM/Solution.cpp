// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int dx [8] ={-1,-1,1,1,-1,0,0,1};
      int dy[8] = {-1,1,-1,1,0,1,-1,0};
      bool visited[105][105];
      memset(visited,false ,sizeof(visited));
      int n = grid[0].size();
        // edge case
      if(grid[0][0] ==1 || grid[n-1][n-1] ==1){
          return -1;
      }
        queue <pair <int,int> > q; // stores row number and column number
        q.push(make_pair(0,0));
        visited[0][0]=true;
        int steps =1;
        bool flag = false;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair <int,int> cur =q.front();
                q.pop();
                if(cur.first == n-1 && cur.second == n-1){
                    flag = true;
                    return steps;
                }
                
                for(int i =0;i<8;i++){
                    int nr = cur.first+dx[i];
                    int nc = cur.second +dy[i];
                    if(nr>=0 && nr< grid.size() && nc>=0 && nc<grid[0].size() && !visited[nr][nc] && grid[nr][nc] ==0){
                        q.push(make_pair(nr,nc));
                        visited[nr][nc] =true;
                    }
                }
                
            }
            steps ++;
        }
        if(!flag)
            return -1;
        return true;
       
    }
};