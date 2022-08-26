// https://leetcode.com/problems/target-sum

class Solution {
public:
    
    int backtrack(vector<int> &nums,int index ,int sum,int target){
        if(index == nums.size()){
            return sum == target ? 1:0;
        }
        return backtrack(nums,index+1,sum+nums[index],target) +
            backtrack(nums,index+1,sum-nums[index],target);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
       return backtrack(nums,0,0,target);  
    } 
};