// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       set <string > word_set(wordDict.begin(),wordDict.end());
       
        cout<<"s.size() is "<<s.size()<<endl;
        cout<<"s.length() is "<<s.length()<<endl;
        int  dp [s.size()+1];
       dp[0] =1 ;// empty string
       
       for(int i =1 ;i<= s.size();i++){
           for(int j=0 ;j<i ;j++){
               if( dp[j] == 1 && word_set.find(s.substr(j,i-j)) != word_set.end()){
                   dp[i] = 1 ;
                   break;
               }
           }
       }
        return dp [s.size()];
    }
};