// https://leetcode.com/problems/valid-palindrome-iii

class Solution {
public:
    int dp[1001][1001];
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        memset(dp,0,sizeof(dp));
        for(int i =s.size()-1;i>=0;i--){
            dp[i][i] =1 ;
            for(int j = i+1;j<n ;j++){
               if(s[i] == s[j]){
                   dp[i][j] = dp[i+1][j-1]+2;
               }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
                
            }
        }
        return dp[0][n-1] +2 >= n ? true:false;
        
    }
};