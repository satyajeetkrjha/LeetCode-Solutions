// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        // dp(i,j) tells us whether the substring from  i to j is a palindrome or not
        // so dp(i,j) = 1 means palindrome
        // and dp(i,j) = 0 means non palindrome
        
        int n = s.size();
        int dp[n][n];
        int ans =0 ;
        
        // all substrings of lenth 1 is a palindrome
        for(int i =0 ;i < n ;i++){
            dp[i][i] = 1;
            ans ++;
        }
        
        // now we will solve for palindromes of lenggth 2 
        
        //dp(i,i+1) means words of size 2 length
        for(int i =0 ;i< n-1;i++){
            dp[i][i+1] = s[i] == s[i+1] ? 1 :0;
            ans += dp[i][i+1];
        }
        
        
        
        /*
        
        now we will solve for palindromes of length 3 and greater than 3 
        we will check whether the last and the first word of the considered word is same or not.if they are same then we just need to check if 
        dp(i+1 ,j-1) is true or not because dp(i+1,j-1) solves for the substring 
     i-1......... j-1 and we already solved this previously
        
        */
        
        for(int len = 3 ;len <= n;len++){
            for(int i = 0 ,j = i+len-1;  j<n;i++,j++){
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j] ;
                ans += dp[i][j];
            }
        }
        return ans ;
        
        
        
        
        
        
        
    }
};