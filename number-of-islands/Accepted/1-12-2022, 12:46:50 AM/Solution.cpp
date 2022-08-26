// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid ,int r ,int c){
       // cout <<"here "<< r <<"  "<< c << endl;
        if(r <0 || c< 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c]=='0' || grid[r][c]=='2')
            return;
        
        if(grid[r][c] =='1'){
             grid[r][c] ='2';
        }
       
        
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res =0 ;
        for(int i =0 ;i<rows;i++){
            for(int j =0 ;j<cols ;j++){
                if(grid[i][j] =='1'){
                 //   cout <<"i and j are "<< i << "   "<< j << endl;
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res ;
    }
};