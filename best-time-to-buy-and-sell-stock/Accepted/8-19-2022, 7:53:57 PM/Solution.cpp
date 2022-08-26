// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = INT_MAX ;
        int maxgain =0;
        for(int i =0 ;i<prices.size();i++){
            smallest= min(smallest ,prices[i]);
            maxgain = max(maxgain ,prices[i]-smallest);
        }
        return maxgain ;
    }
};