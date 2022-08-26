// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        /*
        int dp[m+1][n+1];
    
        for(int i =0 ;i<m;i++){
            for(int j =0 ;j<n;j++){
                dp[i][j] =0;
            }
        }
        */
        
        for(int i = dp.size()-1 ;i>=0 ;i--){
            for(int j = dp[0].size()-1;j>=0 ;j--){
                if( i == dp.size()-1 && j ==  dp[0].size()-1){
                    dp[i][j] =1;
                }
                else if( i == m-1){
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
                    else if(p[i] ==  s[j]){
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