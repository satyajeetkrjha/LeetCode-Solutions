// https://leetcode.com/problems/making-a-large-island

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r ,int c ,int landId){
        if(r<0 || c<0 || r>= grid.size() || c >= grid[0].size() || grid[r][c]!=1)       {
            return 0;
        }
        grid[r][c]=landId;
        int left = dfs(grid,r-1,c,landId);
        int right = dfs(grid,r,c+1,landId);
        int top = dfs(grid,r+1,c,landId);
        int bottom = dfs(grid,r,c-1,landId);
        return left+right+top+bottom+1;
        
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int cols = grid[0].size();
        int landId = 2;
        map <int ,int> m;
        for(int i=0;i<n;i++){
            for(int j =0 ;j<cols;j++){
                if(grid[i][j] ==1){
                    // calculate component size for each 
                    int count = dfs(grid,i,j,landId);
                    m[landId] = count ;
                    landId++;
                    
                }
                
            }
        }
        
        cout <<"landId is "<<landId<<endl;
        cout <<m[2]<<endl;
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
       
        int maxval = INT_MIN;
        int sum =0;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<cols;j++){
                
                
                
                if(grid[i][j] ==0){
                     set <int> seen ;
                    sum =0;
                    for(int k =0 ;k<4;k++){
                        int nr = i+dx[k];
                        int nc = j+dy[k];
                        if(nr >=0 && nc>=0 && nr <grid.size() && nc <grid[0].size()  && grid[nr][nc]!=0){
                            int corrlandid = grid[nr][nc];
                            seen.insert(corrlandid);
                        }
                    }
                    
                    for(auto it :seen){
                        sum += m[it];
                    }
                    maxval = max(maxval,sum);
                }
            }
        }
        return maxval+1;
        
        
        
        
        
        
    }
};