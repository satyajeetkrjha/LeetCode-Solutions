// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    
   
    
    bool dfs(vector<int> nums,int index ,int subsetsum,vector <vector <int> > &cache){
        if(subsetsum == 0){
            return true;
        }
        if(index == 0 || subsetsum <0){
            return false;
        }
        
        if(cache[index][subsetsum]!= -1){
            return (cache[index][subsetsum]==true);
        }
        bool res = dfs(nums,index-1,subsetsum-nums[index-1],cache)
            || dfs(nums,index-1,subsetsum,cache);
        cache[index][subsetsum] = res;
        return res ;
    
        
    }
    
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int totalsum = 0 ;
        for(int i =0 ;i<nums.size();i++){
            totalsum+= nums[i];
        }
         if(totalsum % 2 !=0){
            return false;
        }
        
        int subsetsum = totalsum /2;
        
         vector <vector <int> > cache(n+1,vector<int> (subsetsum+1,-1));
       
        return dfs(nums,n-1,subsetsum,cache);
        
        
    }
};