// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        int ans =0 ;
        int n = nums.size();
        for(auto &it:nums){
            ans +=abs(nums[n/2] - it );
        }
        return ans ;
        
    }
};