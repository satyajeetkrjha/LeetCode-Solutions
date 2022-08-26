// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start =0;
        int end =0;
        map <char,int > m;
        map <char,int>::iterator it;
        int max_len=0;
        while(end <s.size()){
            char c = s[end];
            // check if character exits in the map  and the index is within range
            it =m.find(c);
            if(it!=m.end() && start <=it->second){ // it->econd > start means that this character already exits in the window (start,...,end)
                
             start =it->second+1;   
            }
            m[c]=end++;
            max_len =max(max_len,end-start);
        }
        return max_len;
    }
};