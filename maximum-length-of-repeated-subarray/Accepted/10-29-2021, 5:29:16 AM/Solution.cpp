// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // just longest common substring 
        int n = nums1.size() ;
        int m = nums2.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        
        int res =0;
        for(int i = 0 ;i<= n;i++){
            for(int j = 0 ;j<= m;j++){
                if( i == 0 || j ==0 ){
                    dp[i][j] =0 ;
                }
                else if (nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(res ,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return res ;
        
        
    }
};