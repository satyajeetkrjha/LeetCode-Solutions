// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int totaljumps =0;
        int maxjumpindex =0;
        int currentmaxjumpindex =0;
        for(int i =0 ;i<nums.size()-1 ;i++){
            maxjumpindex = max(maxjumpindex ,nums[i]+i);
            if(i == currentmaxjumpindex){
                totaljumps++;
                currentmaxjumpindex = maxjumpindex;
            }
        }
        return totaljumps ;
    }
};