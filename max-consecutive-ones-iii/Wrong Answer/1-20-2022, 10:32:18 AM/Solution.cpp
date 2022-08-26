// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0 ;
        int right =0 ;
        int windowlen =0 ;
        int ones =0 ;
        int zeroes =0;
        while(left<=right && right <nums.size()){
            if(nums[right] == 0){
                zeroes++;
            }
            else {
                ones++;
            }
            if(zeroes <=k){
                right ++;
                windowlen = max(windowlen ,right-left+1);
            }
            else{
                left++;
                zeroes--;
            }
        }
        return windowlen ;
    }
};