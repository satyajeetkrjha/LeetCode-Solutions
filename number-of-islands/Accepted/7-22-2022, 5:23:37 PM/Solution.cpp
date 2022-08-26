// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid ,char color ,int r ,int c){
        if(r<0 || c<0 || r>= grid.size() || c>=grid[0].size() || grid[r][c]!='1')
            return ;
        grid[r][c] = '#';
        dfs(grid,color,r+1,c);
        dfs(grid,color,r-1,c);
        dfs(grid,color,r,c+1);
        dfs(grid,color,r,c-1);
    }
    
    
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        int count =0 ;
        int n = grid.size();
        int m = grid[0].size();
        char color='#' ;
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j< m;j++){
                if(grid[i][j] == '1'){
                    count ++;
                    dfs(grid,color,i,j);
                }
            }
        }
        return count ;
    }
};