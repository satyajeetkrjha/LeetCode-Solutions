// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced


/*

1. You can always take current character if it's b because
a substring ending with b can't be made invalid by the last b
2. If it's a, you can:
2a. Either drop it with cost dp[i]+1, or
2b. Keep it, in which case you need to drop every b seen till now


*/

class Solution {
public:
    int minimumDeletions(string s) {
        int l = s.size();
        int dp[l+1];
        memset(dp,0,sizeof(dp));
        
        int bcount =0 ;
        for(int i =0 ;i < l ;i++){
            char c = s[i];
            if(c == 'a'){
                dp[i+1] = min(dp[i]+1,bcount);
            }
            else{
                dp[i+1]= dp[i];
                bcount++;
            }
        }
    
        return dp[l];
        
    }
};