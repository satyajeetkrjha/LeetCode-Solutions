// https://leetcode.com/problems/sum-of-subarray-ranges

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int res =0 ;
        int n = nums.size();
        for(int i =0 ;i< n;i++){
            int ma = nums[i];
            int mi = nums[i];
            for(int j = i ;j< n;j++){
                ma = max(ma,nums[j]);
                mi= min(mi ,nums[j]);
                res += (ma - mi);
            }
        }
        return res ;
    }
};