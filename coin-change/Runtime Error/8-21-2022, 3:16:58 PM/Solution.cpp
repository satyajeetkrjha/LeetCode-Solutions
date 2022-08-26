// https://leetcode.com/problems/coin-change

class Solution {
public:
    const int INF = INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        
        for(int i =1 ;i<=amount ;i++)
            dp[i] =INF;
        
        dp[0] = 0;
        
        for(int i =1 ;i<=amount ;i++){
            for(int j =0 ;j<coins.size();j++){
                if(i-coins[j]>=0){
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 :dp[amount];
    }
};