// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    
    bool dfs(vector<int>&nums,int index ,int subsetsum){
        if(subsetsum == 0){
            return true;
        }
        if(index == 0 || subsetsum <0){
            return false;
        }
        bool result = dfs(nums,index-1,subsetsum-nums[index-1] )|| dfs(nums,index-1,subsetsum);
        return result ;
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum =0 ;
        for(auto it: nums){
            totalsum+= it;
        }
        if(totalsum%2 !=0)
            return false;
        
        int subsetsum = totalsum/2;
        return dfs(nums,n-1,subsetsum);
        
    }
};