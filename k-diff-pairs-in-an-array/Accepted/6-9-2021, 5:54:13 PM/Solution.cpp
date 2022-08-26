// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int left =0;
        int right =1;
        int result =0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        while(left <n && right <n ){ // there may be case where left == right so don't 
            if((nums[right]-nums[left] <k )|| (left == right)){
                right++;
            }
            else if(nums[right]-nums[left]>k){
                left++;
            }
            else {
                result++;
                left++;
                while(left <n && nums[left] == nums[left-1]){
                    left++;
                }
            }
        }
        return result ;
    }
};