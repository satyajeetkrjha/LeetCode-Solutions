// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
  
    int minStartValue(vector<int>& nums) {
        
    int minval =0;
    int prefixsum =0;
    for(int i =0 ;i<nums.size();i++){
             prefixsum += nums[i];
             minval = min(minval,prefixsum);
        }
       return (-minval)+1 ;
    }
   
};