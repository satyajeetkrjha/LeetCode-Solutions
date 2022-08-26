// https://leetcode.com/problems/detect-cycles-in-2d-grid

class Solution {
public:
    int count =0;
    bool dfs(vector<vector<char>>& grid,int r ,int c ,int prevr,int prevc,vector <vector<int>> &visited,char ch){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c]!=ch){
            return false;
        }
        if(visited[r][c] -visited[prevr][prevc] >= 3){
            return true;
        }
        if(visited[r][c]!=0)
            return false;
        
        visited[r][c]=count++;
        
        
        return 
            dfs(grid,r+1,c,r,c,visited,grid[r][c]) ||
            dfs(grid,r-1,c,r,c,visited,grid[r][c]) ||
            dfs(grid,r,c+1,r,c,visited,grid[r][c]) ||
            dfs(grid,r,c-1,r,c,visited,grid[r][c]);
        
    }
    
    
    
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector < vector <int> > visited(rows ,vector <int> (columns,0));
        for(int i =0 ;i<rows;i++){
            for(int j =0 ;j<columns ;j++){
                if(visited[i][j] ==0){
                    bool ans = dfs(grid,i,j,i,j,visited,grid[i][j]);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};