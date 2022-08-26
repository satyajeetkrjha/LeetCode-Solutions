// https://leetcode.com/problems/coin-change

#define LARGE 10005
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      int dp[LARGE];
      for(int i =1 ;i<=amount;i++){
          dp[i] =LARGE;
      }
        for(int i =1 ;i<= amount ;i++){
            for(int j =0 ;j<coins.size();j++){
                if(coins[j]<=i){ // 
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
       if(dp[amount] == LARGE)
           return -1;
        return dp[amount];
    }
};