// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
    
        int maxelement =INT_MIN;
        int negative =0 ;
        int positive =0 ;
        
        for(int i =0 ;i<nums.size();i++){
            if(nums[i] == 0){
                negative =0 ;
                positive =0;
            }
            else if(nums[i] > 0){
                positive ++;
                negative = negative  == 0  ? 0 : negative +1;
            }
            else {
                int temp = positive ;
                positive = negative == 0 ? 0 :negative +1;
                negative = temp+1;
            }
            maxelement = max(maxelement ,positive);
        }
        return maxelement ;
    }
};