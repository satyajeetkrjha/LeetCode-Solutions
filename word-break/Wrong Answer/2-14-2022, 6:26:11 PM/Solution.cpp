// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set <string> words ;
        
        for(auto word:wordDict){
            words.insert(word);
        }
        
        int sz = s.size();
        int dp[sz+1];
        
        for(int i =0 ;i<sz+1;i++){
            dp[0] =0;
        }
       
        dp[0] =1 ;
        for(int i = 1 ;i<=s.size();i++){
            for(int j =0 ;j< i;j++){
                 if(dp[j] =1 && words.find(s.substr(j,i-j))!=words.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[sz];
        
    }
};