// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int lis[n+2];
        for(int i =0 ;i< n;i++) lis[i] = 1;
        
        for(int i = 0 ;i< n;i++){
            for(int j =0 ;j< i ;j++){
                if(nums[i] >= nums[j]){
                    lis[i] =lis[j]+1;
                }
            }
        }
        
        int ans =0 ;
        for(int i =0 ;i < n;i++)
            ans = max(ans ,lis[i]);
        
        return ans ;
        
    }
};