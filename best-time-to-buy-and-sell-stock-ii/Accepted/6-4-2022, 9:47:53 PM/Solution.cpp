// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int ans =0;
    int maxProfit(vector<int>& prices) {
        for(int i =1 ;i<prices.size();i++){
            if(prices[i] > prices[i-1])
            ans += prices[i]-prices[i-1];
        }
        return ans ;
    }
};