// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        int ans = 0 ;
        map <char ,int> m ;
        int start =0 ;
        int end =0 ;
        while(end <s.size()){
            char c = s[end];
            for(auto it:m){
                if(it.first == c && it.second >=start && it.second <end){
                    start = it.second+1;
                }
            }
            m[c] = end++;
            ans = max(ans ,end-start);
        }
        return ans;
    }
};