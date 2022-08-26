// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int xorsum =0 ;
        int n = nums.size();
      for(int i =0 ;i<=n;i++){
          xorsum = xorsum^ i;
      }
        for(int i =0 ;i<nums.size();i++){
            xorsum^=nums[i];
        }
        return xorsum ;
    }
};