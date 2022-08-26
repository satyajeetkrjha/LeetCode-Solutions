// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorsum =0 ;
        for(auto &it:nums){
            xorsum ^= it;
        }
        return xorsum ;
    }
};