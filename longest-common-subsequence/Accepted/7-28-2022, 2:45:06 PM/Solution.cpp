// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();int m = text2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int col = text2.size()-1;col>=0 ;col--){
            for(int row = text1.size()-1;row>=0 ;row--){
                if(text1[row] == text2[col]){
                    dp[row][col] = 1 + dp[row+1][col+1];
                }
                else{
                    dp[row][col] = max(dp[row+1][col],dp[row][col+1]);
                }
            }
        }
        return dp[0][0];
    }
};