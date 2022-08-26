// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        if(n == 2)
            return 2 ;
            
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3 ;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};