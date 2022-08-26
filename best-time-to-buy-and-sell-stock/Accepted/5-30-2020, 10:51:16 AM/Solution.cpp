// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxPrice=0;
        for(int i=0;i<prices.size();i++){
            minPrice =min(minPrice,prices[i]);
            maxPrice=max(prices[i]-minPrice,maxPrice);
            
        }
        return maxPrice;
    }
};