// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0 ;
        int right = 0 ;
        int best =INT_MIN ;
        int zerocount = 0;
        int n = nums.size();
        while(right <n){
            if(zerocount <= k){
                if(nums[right] == 0){
                    zerocount++;
                }
                right ++;
            }
            if(zerocount > k){
                if(nums[left] == 0){
                    zerocount--;
                }
                left ++;
            }
            if(right - left > best && zerocount<=k){
                best = max(best,right- left);
            }
        }
        return best ;
        
    }
};