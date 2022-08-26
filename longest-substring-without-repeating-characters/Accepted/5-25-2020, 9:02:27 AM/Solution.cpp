// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int start =0;
        int end =0;
        map <char,int> m;
        map <char,int >::iterator it ;
        int max_len =0;
        while(end <s.size()){
            char c = s[end];
            it =m.find(c);
            if(it!=m.end() && it->second >= start && it->second <end){
                start =it->second+1;
            }
            m[c]=end++;
            max_len=max(max_len,end-start);
        }
        return max_len;
    }
};