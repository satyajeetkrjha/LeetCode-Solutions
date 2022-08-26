// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxsofar = nums[0];
        int minsofar = nums[0];
        int result = nums[0];
        for(int i = 1;i <nums.size();i++){
            int curr = nums[i];
            int temp_max = max(curr,max((maxsofar*curr),(minsofar*curr)));
             minsofar = min(curr,min((maxsofar*curr),(minsofar*curr)));
            maxsofar=temp_max;
            result = max(result ,maxsofar);
        }
        return result ;
    }
};