// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n = nums.size();
         /*
         
        Fisrt case where all are positive so if numbers are 
          200 100 300 400 600 700 -> 100 200 300 400 600 700 
          so max product is product of last three numbers after sorting 
          
          100 200 -10000 -900 1999999
          -> -100000 -9000 100 200 1999999
           so max product is -100000 *-90000*1999999 
           as first two extremely small numbers on left multiplies to become large 
        
        
        
        */
        
         int max1 = nums[n-1]*nums[n-2]*nums[n-3];
         int max2 = nums[0]*nums[1]*nums[nums.size()-1];
        return max(max1,max2);
    }
};