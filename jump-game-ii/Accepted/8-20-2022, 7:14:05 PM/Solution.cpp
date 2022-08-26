// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int total =0 ;
        int curfarthest =0 ;
        int curend = 0 ;
        int n =nums.size() ;
        for(int i =0 ;i<n-1;i++){
            curfarthest = max(curfarthest ,nums[i]+i);
            if(i == curend){
                total++;
                curend = curfarthest;
            }
        }
        return total ;
        
        
    }
};