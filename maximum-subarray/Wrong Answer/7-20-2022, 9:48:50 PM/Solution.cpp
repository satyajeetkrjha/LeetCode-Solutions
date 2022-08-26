// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int currentsum =0;
        int maxsum =0 ;
        for(int i =0 ;i<nums.size();i++){
            currentsum += nums[i];
            if(currentsum <0){
                currentsum = 0;
            }
            maxsum = max(maxsum ,currentsum);
        }
        return maxsum ;
    }
};