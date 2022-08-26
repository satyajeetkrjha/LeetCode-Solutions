// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastreachable = n-1;
        for(int i = n-2;i>=0;i--){
            if(i+nums[i]>=lastreachable){
                lastreachable =i;
            }
        }
        return lastreachable == 0 ;
    }
};