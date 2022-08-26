// https://leetcode.com/problems/target-sum

class Solution {
public:
    int target;
    int n ;
    vector<int> nums ;
    
    int backtrack(int index ,int total){
        if (index == n){
            return total == target ? 1 : 0 ;
        }
      
        return 
            backtrack(index+1,total+nums[index])+backtrack(index+1,total-nums[index]);

            
    }
    int findTargetSumWays(vector<int>& nums1, int target1) {
        target = target1 ;
        nums = nums1 ;
        n = nums.size();
        return backtrack(0,0);
        
    }
};