// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor_sum =0;
        for(int i=0;i<nums.size();i++){
            xor_sum =xor_sum^nums[i];
        }
        return xor_sum;
    }
};