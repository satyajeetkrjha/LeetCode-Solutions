// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans =0;
        if(m == 0) return 0; 
        
        int dp[n+1][m+1][4];
        memset(dp,0,sizeof(dp));
        
        for(int i =0 ;i< n;i++){
            for(int j =0 ;j<m ;j++){
                if(mat[i][j] == 1){
                    dp[i][j][0] =  i > 0 ? dp[i-1][j][0]+1:1;
                    dp[i][j][1] =  j > 0 ? dp[i][j-1][0]+1:1;
                    dp[i][j][2] =  (i > 0 && j > 0) ? dp[i-1][j-1][2]:1;
                    dp[i][j][3] =   (i >0 && j <m )? dp[i][j+1][3]:1 ;
                    ans = max(ans , 
                              max(
                              max(dp[i][j][0],dp[i][j][1]),
                              max(dp[i][j][2],dp[i][j][2])
                             ));
                }
            }
        }
        return ans ;
    }
};