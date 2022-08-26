// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastgoodposition = nums.size()-1 ;
        //initially the last index is going to be our good position 
        for(int i = nums.size()-1 ;i>=0 ;i--){
            if(i+ nums[i] >= lastgoodposition){
                lastgoodposition =i; // last good position is updated now so when you are at i-2 ,you need to know as from that position you can reach i-1 or not
            }
        }
        return lastgoodposition == 0 ? true:false;
        
    }
};