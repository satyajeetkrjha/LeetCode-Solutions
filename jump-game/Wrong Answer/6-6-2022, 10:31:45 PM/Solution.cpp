// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        n = n-2 ;
        int lastindex = n-1 ;
        for(int i = n;i>=0;i--){
            if(nums[i]+i>=lastindex){
                lastindex =i;
            }
        }
        return lastindex == 0 ;
        
        
    }
};