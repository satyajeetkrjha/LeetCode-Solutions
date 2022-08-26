// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int inclusive = nums[0];
        int exclusive =0;
        int exclusive_new ;
        for(int i =1 ;i<nums.size();i++){
            exclusive_new = max(inclusive,exclusive);
            inclusive = nums[i]+ exclusive ;
            exclusive = exclusive_new ;
        }
        return max(inclusive ,exclusive);
    }
};