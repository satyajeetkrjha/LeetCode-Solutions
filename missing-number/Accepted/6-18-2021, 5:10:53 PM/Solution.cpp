// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      int expectedsum = (n*(n+1))/2;
      int actualsum =0;
      for(int i =0;i<nums.size();i++){
          actualsum+=nums[i];
      }
        return expectedsum - actualsum;
    }
};