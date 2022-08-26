// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstlen, int secondlen) {
        int n  = nums.size();
        int prefixsum [n+1];
        prefixsum[0] = nums[0];
        for(int i=1;i<=n;i++){
            prefixsum[i] = prefixsum[i-1]+nums[i-1];
        }
        int max_sum =0;
        for(int i =0;i<=n-firstlen;i++){
            int first_sum = prefixsum[i+firstlen]-prefixsum[i];
            
            for(int j =i+firstlen ;j<=n-secondlen;j++){
                int second_sum = prefixsum[j+secondlen]-prefixsum[j];
                max_sum = max(max_sum,second_sum+first_sum);
            }
            for(int j =0;j<=i-secondlen;j++){
                int second_sum = prefixsum[j+secondlen]-prefixsum[j];
                max_sum = max(max_sum,second_sum+first_sum);
            }
        }
        return max_sum;
        
    }
};