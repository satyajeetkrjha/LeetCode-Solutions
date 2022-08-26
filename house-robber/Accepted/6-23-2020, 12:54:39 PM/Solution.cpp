// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() ==0)
            return 0;
        int inclusive =nums[0];
        int exclusive =0;
        int exclusive_new;
        for(int i=1;i<nums.size();i++){
            exclusive_new = max(inclusive,exclusive);
            inclusive =exclusive+nums[i];
            exclusive = exclusive_new;
        }
        return max(inclusive,exclusive);
    }
};