// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    
        set <string> st ;
        for(auto &word:wordDict){
            st.insert(word);
        }
        int n = s.size();
        int dp[n+1];
        for(int i =0 ;i<n;i++) dp[i] =0;
        dp[0] = 1;
        
        for(int i =1 ;i<=n;i++){
            for(int j =0 ;j<i ;j++){
                if(dp[j]  && st.find(s.substr(j,i-j))!=st.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }             
      return dp[n];
    }
};