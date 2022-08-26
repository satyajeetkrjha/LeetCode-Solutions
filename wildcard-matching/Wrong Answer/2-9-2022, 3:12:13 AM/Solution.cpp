// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int dp[m+1][n+1];
        
        for(int i = m-1 ;i>=0 ;i--){
            for(int j = n-1;j>=0 ;j--){
                if( i == m-1 && j ==n-1){
                    dp[i][j] =1;
                }
                else if( i ==m-1){
                    dp[i][j] = 0;
                }
                else if(j == n-1){
                    if(p[i] =='*'){
                        dp[i][j] = dp[i+1][j];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    if(p[i] == '?'){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else if(p[i] =='*'){
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    }
                    else if(p[i] ==  p[j]){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                    
                }
            }
        }
        return dp[0][0];
        
    }
};