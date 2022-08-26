// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

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