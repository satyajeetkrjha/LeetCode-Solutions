// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int n = obstacleGrid.size();
         int m = obstacleGrid[0].size();
        
         int dp [n+1][m+1];
         memset(dp ,0,sizeof(dp));
        
         if(obstacleGrid[0][0] ==1) return 0;
         dp[0][0] =1;
        
         for(int i =1 ;i<n;i++){
             dp[i][0] = obstacleGrid[i][0] == 1 ? 0: dp[i-1][0];
         }
         
        for(int i =1 ;i<m;i++){
            dp[0][i] = obstacleGrid[0][i] ==1 ? 0:dp[0][i-1];
        }
        
        for(int i =1 ;i<n;i++){
            for(int j =1 ;j<m;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] =0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
          return dp[n-1][m-1];
     
        
    }
};