// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int ans =0 ;
        for(int j =0 ;j< nums.size();j+=3){ 
            
             if(j+1 <nums.size() && j+2 <nums.size()){
                    if(nums[j] ==nums[j+2] && nums[j+2]!=nums[j+1]){
                      continue;
                }
                if(nums[j]!=nums[j+1]){
                    ans += abs(nums[j+1]-nums[j]);
                    nums[j] = nums[j+1];
                }
                if(nums[j+1] == nums[j+2]){
                   ans++;
                    nums[j+1]=nums[j+1]+1;
            
                }    
              }    
            }   
        
        return ans;
        
    }
};