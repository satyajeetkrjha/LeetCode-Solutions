// https://leetcode.com/problems/two-sum-less-than-k

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l =0;
        int r = nums.size() -1;
        int maxsum =-1;
        while(l<r){
            int sum =nums[l]+nums[r];
            if(sum<k){
                maxsum =max(maxsum,sum);
                l++;
            }
            else {
                r--;
            }
        }
        return maxsum ;
    }
};