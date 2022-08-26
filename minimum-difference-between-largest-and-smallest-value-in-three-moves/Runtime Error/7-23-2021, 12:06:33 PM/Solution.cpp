// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int ans=INT_MAX;
        int n = nums.size();
      ans = min ( min(nums[n-4]-nums[0],nums[n-1]-nums[3]),min(nums[n-2]-nums[2],nums[n-3]-nums[1]));
        return ans ;
    }
};