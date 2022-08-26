// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int smallest = INT_MAX;
    int maxGain =0;
    int maxProfit(vector<int>& prices) {
        
     for(int i =0 ;i<prices.size();i++){
        smallest = min(smallest ,prices[i]);
        maxGain = max(maxGain,prices[i]-smallest);  
     }
       return maxGain;  
    }
   
};