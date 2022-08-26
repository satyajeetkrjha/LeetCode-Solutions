// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int minPrice=INT_MAX;
    int maxprofit =0;
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       for(int i = 0;i<n ;i++){
           minPrice = min(minPrice,prices[i]);
           // cout<<"minPrice is "<<minPrice<<endl;
           maxprofit = max(maxprofit,prices[i]-minPrice);
           // cout<<"maxProfit is "<<maxprofit <<endl;
       } 
        return maxprofit ;
    }
};