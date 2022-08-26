// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
       
        unordered_map<int, int> sum2count;
        int sum = 0;
        int count = 0;
       
        sum2count[0] = 0;
        
        for(int i = 0; i < n; ++i){
         
            sum += nums[i];
            
            if(sum2count.find(sum-target) != sum2count.end()){
             
                count = max(count, sum2count[sum-target] + 1);
            }
            
            sum2count[sum] = count;
        }
        
        return count;
    }
};