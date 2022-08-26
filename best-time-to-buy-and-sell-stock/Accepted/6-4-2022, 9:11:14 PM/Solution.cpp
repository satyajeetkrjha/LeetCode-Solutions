// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int smallest ;
    int maxprofit =INT_MIN;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n ==1 )
            return 0;
        smallest = prices[0];
        for(int i =1 ;i<n;i++){
            smallest = min(smallest,prices[i]);
            maxprofit = max(maxprofit ,prices[i] -smallest);
        }
        return maxprofit ;
    }
};