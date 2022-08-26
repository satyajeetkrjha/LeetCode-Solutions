// https://leetcode.com/problems/sum-of-subsequence-widths


const long long int  mod = 1e9+7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
    
        int res =0 ;
        int c = 1 ;
        int n = nums.size();
        for(int i =0 ;i< nums.size();i++,c = c*2 %mod){
            res+= (nums[i]*c -nums[n-i-1]*c)%mod;
        }
        return (res+mod)%mod;
    }
};