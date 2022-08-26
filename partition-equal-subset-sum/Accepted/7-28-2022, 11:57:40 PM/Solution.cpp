// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    vector <int> nums ;
    
    bool flag = false ;
    int sum ;
    map <pair <int,int> ,int>m;
    int backtrack(int index ,int cursum,vector<int>&nums){
        
        
        if(index>=nums.size()){
            return cursum == (sum/2) ? 1 : 0 ;
        }
        auto it = m.find({index,cursum});
        if(it!=m.end()){
            return it->second ;
        }
        m[{index,cursum}] =backtrack(index+1,cursum+nums[index],nums)
         || backtrack(index+1,cursum,nums);
        return m[{index,cursum}];
    }
    
    
    
    
    
    
    
    
    bool canPartition(vector<int>& nums) {
       
        sum = 0 ;
        for(int i =0 ;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum %2 !=0)
            return false ;
        return backtrack(0,0,nums);
        
    }
};