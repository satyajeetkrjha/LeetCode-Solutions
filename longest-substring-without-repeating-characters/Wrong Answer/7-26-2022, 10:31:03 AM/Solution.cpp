// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right = 0 ;
        map <char ,int> m;
        int ans =0;
        if(s.size() == 0)
            return 1;
        while(right < s.size()){
            char ch = s[right];
            if(m.count(ch)>0){
                left = max(left ,m[ch]);
            }
            ans = max(ans ,right-left);
            m[ch] =right ;
            right++;
        }
        return ans ;
    }
};