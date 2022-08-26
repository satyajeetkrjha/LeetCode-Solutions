// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4] ={0,-1,0,1};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0 ;
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                int cell = grid[i][j];
                if(cell ==0)
                    continue;
                else {
                    // decrease cost now
                    int cost =4;
                    for(int val =0 ;val<4;val++){
                        int nr = i +dx[val];
                        int nc = j +dy[val];
                        if(nr>=0 && nc>=0 && nr< n && nc <m){
                            cost = cost - grid[nr][nc];
                        }
                    }
                    ans +=cost;
                    
                    
                }
                
            }
        } 
        return ans ;
        
        
        
    }
};