// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <vector <int > > dp(n,vector<int> (2));
        dp[0][1] = nums[0];
        dp[0][0] = 0 ;
        for(int i = 1 ;i<nums.size();i++){
              dp[i][0] =max(dp[i-1][0],dp[i-1][1]);
              dp[i][1] = nums[i]+dp[i-1][0];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};