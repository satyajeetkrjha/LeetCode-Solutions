// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0 ;
        int right= 0 ;
        int n= nums.size();
        int maxwindowsize = INT_MIN;
        while(right <n){
            if(nums[right] == 0){
                k--;
            }
            if(k<0){
                k+= 1 -nums[left] ; // 1 -1 =0 and  1-0 =1 
                left++;
            }
            maxwindowsize = max(maxwindowsize,right-left+1);
            right ++;
        }
        
        return maxwindowsize ;
    }
};