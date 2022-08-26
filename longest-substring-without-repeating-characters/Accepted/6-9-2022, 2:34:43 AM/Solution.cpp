// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans =0 ;
        int end =0 ;
        int start =0 ;
        map <char ,int> m;
        for(int i =0 ;i<s.size();i++){
            char c = s[i];
            map <char ,int> :: iterator it ;
            for(auto it :m){
                if(it.first == c && it.second >=start && it.second <end){
                   start = it.second+1;
                }
            }
            m[c] = end++;
          ans  = max(ans ,end-start);    
        }
        return ans ;
    }
};