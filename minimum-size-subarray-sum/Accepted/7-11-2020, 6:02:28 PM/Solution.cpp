// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left =0;
        int n = nums.size();
        int sum =0;
        int ans =INT_MAX;
        for(int i=0;i<n;i++){
            sum +=nums[i];
                while(sum>=s){
                    ans= min(ans,i-left+1);
                    sum=sum-nums[left];
                    left++;
                }
        }
        ans =ans ==INT_MAX?0:ans;
        return ans;
    }
};