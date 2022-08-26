// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = INT_MIN;
        int cursum =0;
        for(int i=0 ;i<nums.size();i++){
            cursum+=nums[i];
            maxSum = max(maxSum,cursum);
            if(cursum <0){
                cursum =0;
            }
        }
        return maxSum ;
    }
};