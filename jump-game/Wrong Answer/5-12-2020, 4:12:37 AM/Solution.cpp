// https://leetcode.com/problems/jump-game

#include <iostream>
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int lastgoodPositionIndex =nums.size()-1;
        for(int i= nums.size();i>0;i--){
            if(i+nums[i]>=lastgoodPositionIndex){
                lastgoodPositionIndex =i;
            }
        }
        if(lastgoodPositionIndex ==0){
            return true;
        }
        return false;
    }
};