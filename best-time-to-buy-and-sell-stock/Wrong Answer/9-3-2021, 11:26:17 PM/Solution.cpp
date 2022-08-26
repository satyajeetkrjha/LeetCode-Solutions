// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       // store the largest element to the right index of i 
       int right[n];
        for(int i =0 ;i<n;i++){
            right[i] =0 ;
        }
        right[n-1]= prices[n-1];
        int largest = prices[n-1];
       for(int i =n-2;i>=0 ;i--){
           largest = max(largest,prices[i+1]);
           right[i] = max(right[i],largest);
           cout<<"right[i] now is "<<right[i]<<endl;
           
          
       } 
        
        for(int i = 0 ;i<n ;i++){
            cout<<right[i]<<" ";
        }
        int maxdiff = -1 ;
        for(int i =0 ;i<n-1;i++){
            maxdiff = max(maxdiff ,right[i]-prices[i]);
        }
        return maxdiff ;
    }
};