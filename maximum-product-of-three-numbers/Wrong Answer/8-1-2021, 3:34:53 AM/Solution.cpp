// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n = nums.size();
         int max1 = nums[0]*nums[1]*nums[2];
         int max2 = nums[0]*nums[nums.size()-2]*nums[nums.size()-1];
        return max(max1,max2);
    }
};