// https://leetcode.com/problems/number-of-distinct-islands

class Solution {
public:
    int visited[100][100];
    int numDistinctIslands(vector<vector<int>>& grid) {
        set <string> uniqueislands;
        int r = grid.size();
        int c = grid[0].size();
        if( c==0 )
            return 0;
        int visited[r+1][c+1];
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                string temp="";
                
                if(grid[i][j] ==1 && visited[i][j] ==0){
                     dfs(grid,i,j,i,j,temp);
                }
                
                if(temp.size() != 0)
                uniqueislands.insert(temp);            
                temp="";
               
            }
        }
        return uniqueislands.size();
    }
    void dfs(vector<vector<int>>& grid ,int i,int j,int r,int c,string &temp){
        int n = grid.size();int m = grid[0].size();
        if(i< 0 || j<0 || i>=n || j>= m){
            return;
        }
        if(visited[i][j] ||  grid[i][j] == 0){
            return ;
        }
        visited[i][j] =1;
        temp+=to_string(r-i)+to_string(c-j);
        
        
        dfs(grid,i+1,j,r,c,temp);
        dfs(grid,i-1,j,r,c,temp);
        dfs(grid,i,j+1,r,c,temp);
        dfs(grid,i,j-1,r,c,temp);
        
    }
};