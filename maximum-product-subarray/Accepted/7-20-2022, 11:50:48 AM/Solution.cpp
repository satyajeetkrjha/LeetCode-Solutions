// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxsofar = nums[0];
        int minsofar = nums[0];
        int result = nums[0];
        for(int i =1 ;i<nums.size();i++){
            int cur = nums[i];
            int tempmax = max(cur,max((cur*maxsofar),(cur*minsofar)));
            minsofar = min(cur,min((maxsofar*cur),(minsofar*cur)));
            maxsofar = tempmax;
            result = max(result ,maxsofar);               
        }
                           return result ;
    }
};