// https://leetcode.com/problems/binary-subarrays-with-sum

class Solution {
public:
    
    map <int ,int> m;
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    
        int n = nums.size();
        int prefixsum[n+1];
        int sum =0 ;
        int ans =0;
        
        for(int i =0 ;i< n;i++){
            prefixsum[i+1] = prefixsum[i]+nums[i];
        }
        
        m[goal] =1 ;
        
        for(int i =0 ;i< n;i++){
            int x = prefixsum[i];
            
                ans += m[x];
              m[x+goal]++;
        }
        
        return ans ;
    }
};