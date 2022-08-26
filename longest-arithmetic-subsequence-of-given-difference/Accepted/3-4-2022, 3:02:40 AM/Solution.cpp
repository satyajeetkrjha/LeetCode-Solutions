// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) {
        map <int ,int> dp ;
        int ans = 1;
        for(int &i:arr){
            ans = max(ans,dp[i] = dp[i-k]+1);
        }
        return ans ;
    }
};