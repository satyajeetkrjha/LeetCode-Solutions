// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int num =INT_MAX;
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            num = min(num,nums[i]);
        }
       return sum-n*num;
    }
};