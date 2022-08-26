// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right = 0 ;
        map <char ,int> m;
        int maxsize =1 ;
        while(right <s.size()){
              char ch = s[right];
            if(m[ch]>0){
                maxsize = max(maxsize ,right-left);
                left = m[ch];
            }
            right++;
            ++m[s[right]];
        }
        return maxsize -1;
    }
};