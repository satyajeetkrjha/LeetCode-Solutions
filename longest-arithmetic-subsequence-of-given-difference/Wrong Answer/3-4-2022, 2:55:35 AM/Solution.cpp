// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {
        map <int ,int> dp ;
        int ans = 1;
        for(int i = 0 ;i< arr.size();i++){
            if(dp.count(i-k) >0){
                dp[i] = 1 + dp[i-k];
            }
            else{
                dp[i] =1 ;
            }
            ans = max (ans ,dp[i]);
        }
        return ans ;
    }
};