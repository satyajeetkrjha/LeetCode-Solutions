// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
     
        int n = nums.size();
        int curfarthest = 0 ;
        int total = 0 ;
        int curEnd = 0 ;
        for(int i =0 ;i< n-1;i++){
            curfarthest =max(curfarthest ,nums[i]+i);
            if( i == curEnd){
                total++;
                curEnd = curfarthest ;
            }
        }
        return total ;   
    }
};