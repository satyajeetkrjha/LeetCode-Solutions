// https://leetcode.com/problems/making-a-large-island

class Solution {
public:
    
    int dx[4]= {1,-1,0,0};
    int dy[4]= {0 ,0,1,-1};
    
     // this dfs returns the size of the 1's 
      int dfs (vector<vector<int>>& grid,int i ,int j ,int islandId){
            if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]!=1){
                return 0;
            }
            grid[i][j] =islandId;
            int left = dfs( grid ,i,j-1,islandId);
            int right = dfs(grid,i,j+1,islandId);
            int up = dfs(grid,i-1,j,islandId);
            int down = dfs(grid,i+1,j,islandId);
            return left+right+up+down+1;
        }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();int m = grid[0].size();
        int maxVal =0;
        int islandId = 2 ;
        map <int ,int> islandmap; 
        for(int i =0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if( grid[i][j] == 1){
                    int count = dfs(grid,i,j,islandId);
                    cout<<"count is "<<count <<endl;
                    maxVal = max(maxVal ,count);
                    islandmap[islandId]  = count;
                    islandId++;
                }
            }
        }
        // cout<<"here"<<endl;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                set <int> seen ;
                if( grid[i][j] ==0){
                  for(int k =0 ;k<4;k++){
                      int nr = i + dx[k];
                      int nc = j+ dy[k];
                      if(nr >=0  && nc>=0 && nr <grid.size() && nc <grid[0].size() && grid[nr][nc]!=0){
                          seen.insert(grid[nr][nc]);
                      }
                  }
                }
                
                int sum = 1;
                for( auto elem: seen){
                    sum = sum +islandmap[elem];
                }
                maxVal = max(maxVal ,sum);
                
            }
        }
        return maxVal;
        
        
        
        
        
        
        
    }
};