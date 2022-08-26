// https://leetcode.com/problems/number-of-islands

class Solution {
    int count ;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
public:
    void dfs( vector<vector<char>>& grid,int r,int c,int tr,int tc,vector <vector<int> > &visited){
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int nr =r+dx[i];
            int nc =c+dy[i];
            if(nr>=0 && nc>=0 && nr<=tr-1 && nc<=tc-1 && !visited[nr][nc]){
                dfs(grid,nr,nc,tr,tc,visited);
            }
                
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();// number of rows
        int c = grid[0].size();
        vector <vector<int> >visited (r+1, vector <int> (c+1,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,r,c,visited);
                }
                
            }
        }
        return count;
    
    }
};