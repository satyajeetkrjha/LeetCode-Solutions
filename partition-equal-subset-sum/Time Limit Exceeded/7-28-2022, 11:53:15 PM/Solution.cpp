// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    vector <int> nums ;
    
    bool flag = false ;
    int sum ;
    int backtrack(int index ,int cursum){
        if(index>=nums.size()){
            return cursum == (sum/2) ? 1 : 0 ;
        }
        return backtrack(index+1,cursum+nums[index])
         || backtrack(index+1,cursum);
    }
    
    
    
    
    
    
    
    
    bool canPartition(vector<int>& nums1) {
        nums= nums1;
        sum = 0 ;
        for(int i =0 ;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum %2 !=0)
            return false ;
        return backtrack(0,0);
        
    }
};