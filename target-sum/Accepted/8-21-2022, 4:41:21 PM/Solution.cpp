// https://leetcode.com/problems/target-sum

class Solution {
public:
    map <pair <int,int>,int> m ;
    int backtrack(vector<int> &nums,int index ,int sum ,int target){
        if(index == nums.size()){
            return target == sum ? 1:0;
        }
        auto it= m.find({index,sum});
        if(it!=m.end()){
            return it->second;
        }
        return m[{index,sum}] =
            backtrack(nums,index+1,nums[index]+sum,target)
            + backtrack(nums,index+1,sum-nums[index],target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums,0 ,0 ,target);
    }
};