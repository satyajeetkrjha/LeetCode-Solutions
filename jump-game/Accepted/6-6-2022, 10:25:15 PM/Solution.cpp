// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int n = nums.size();
        int lastindex = n-1;
        
        for(int i = n-2;i>=0;i--){
            if(nums[i]+i >= lastindex){
                lastindex = i;
            }
        }
       return lastindex == 0 ;
    }
};