// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size()+2;
        
        vector <int> newNums(n);
        newNums[0] =1 ;
        newNums[n-1]=1;
        for(int i = 1;i<=n-2;i++){
            newNums[i] = nums[i-1];
        }
       
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int left = n-2;left>=1 ;left--){
            for(int right = left ;right <=n-2;right++){
                for(int i = left ;i<=right;i++){
                    int gain = newNums[left-1]*newNums[i]*newNums[right+1];
                    int remaining = dp[left][i-1]+ dp[i+1][right];
                    dp[left][right]  = max(remaining+gain,dp[left][right]);
                }
            }
        }
        return dp[1][n-2];
    }
};