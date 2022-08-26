// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        
        for(int i=0;i<=n;i++){
            dp[i]=0;
        }
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            cout<<"dp[i-1] "<<dp[i-1]<<endl;
            cout<<"dp[i-2] "<<dp[i-2]<<endl;
            dp[i]+=dp[i-1]+dp[i-2];
            cout<<"dp[i] "<<dp[i]<<" with i as "<<i<<endl;
        }
        return dp[n];
    }
};