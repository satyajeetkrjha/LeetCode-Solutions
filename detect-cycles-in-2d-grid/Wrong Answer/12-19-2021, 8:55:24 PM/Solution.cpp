// https://leetcode.com/problems/detect-cycles-in-2d-grid

class Solution {
public:
    int dx[4] ={1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int rows ,columns ;
    
    int dfs (vector<vector<char>>& grid, vector < vector <int> > visited,int r ,int c,char ch,int &val){
        visited[r][c] =1;
        val++;
        for(int i =0 ;i<4 ;i++){
            int nr = r + dx[i];
            int nc = c+ dy[i];
            if(nr >=0 && nr < rows && nc >=0 & nc < columns && !visited[nr][nc] && grid[nr][nc] == ch ){
                dfs(grid,visited ,nr,nc,grid[nr][nc],val);
            }
        }
        return val;
        
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        vector < vector <int> > visited(rows,vector <int> (columns,0));
        
        for(int r =0 ;r <rows ;r++){
            for(int c =0 ;c< columns ;c++){
                char ch = grid[r][c];
                if(visited[r][c] == 0){
                    int val =0;
                    int len = dfs (grid,visited, r,c ,ch,val );
                    if(len >=4){
                        return true;
                    }
                }
            }
        }
      return false;
    }
};