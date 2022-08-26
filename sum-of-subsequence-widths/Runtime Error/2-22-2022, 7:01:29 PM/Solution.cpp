// https://leetcode.com/problems/sum-of-subsequence-widths

const int mod = 1e9+7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        
        int res = 0 ;
        int n = nums.size();
        for(int i =0 ;i< nums.size();i++){
            res+= (nums[i]*pow(2,i));
            res-= (nums[i]*pow(2,n-i-1));
        }
        return res ;
        
        
    }
};