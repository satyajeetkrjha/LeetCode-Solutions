// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxsum =INT_MIN;
        int cursum =0;
        for(auto &it:nums){
            cursum +=it;
            maxsum = max(maxsum,cursum);
            if(cursum <0)
                cursum =0;
            
        }
        return maxsum ;
    }
};