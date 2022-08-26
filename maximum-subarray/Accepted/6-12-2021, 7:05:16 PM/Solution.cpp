// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximumsofar =INT_MIN;
        int maximumendinghere =0;
        for(int i=0;i<nums.size();i++){
            maximumendinghere+=nums[i];
            if(maximumendinghere >maximumsofar){
                maximumsofar = maximumendinghere;
            }
            if(maximumendinghere <0){
                maximumendinghere =0;
            }
        }
        return maximumsofar;
    }
};