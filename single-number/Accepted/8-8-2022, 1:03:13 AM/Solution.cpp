// https://leetcode.com/problems/single-number

class Solution {
public:
    int xorsum =0;
    int singleNumber(vector<int>& nums) {
        for(auto &it:nums){
            xorsum = xorsum ^ it;
        }
        return xorsum ;
    }
};