// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
      sort(nums.begin(),nums.end());
       int n = nums.size();
        if(n<5) return 0;
      int ans=INT_MAX;
      ans = min ( min(nums[n-4]-nums[0],nums[n-1]-nums[3]),min(nums[n-2]-nums[2],nums[n-3]-nums[1]));
        return ans ;
    }
};