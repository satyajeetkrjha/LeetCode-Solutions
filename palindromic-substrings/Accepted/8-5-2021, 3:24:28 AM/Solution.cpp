// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        // dp (i,j) tells us whethere substring from index i to index j in string s is a palindrome
        for(int i =0 ;i<n+1;i++){
            for(int j=0 ;j<n+1;j++){
                dp[i][j] =0;
            }
        } 
        
        // all single letters of string is a palindrome which is dp(i,i)
        //starts at i and ends  at i
        int ans=0;
        for(int i =0 ;i<n;i++){
            dp[i][i] =1 ; 
            ans++;
        }
        
        // all two letter strings calculated
        for(int i =0 ;i<n-1;i++){
            dp[i][i+1] =s[i] == s[i+1] ? 1:0;
            ans += dp[i][i+1];
        }
        
        for(int len = 3 ;len<=n;len++){
            for(int i =0 ,j = i+len-1; j<n; j++,i++){
                // cout<<" i and j are "<<i <<" "<<j<<endl;
                // cout<<"substring length is "<<len<<endl;
                dp[i][j] = dp[i+1][j-1] && s[i]== s[j];
                ans+= dp[i][j];
            }
        
        }
        return ans;  
    }
};