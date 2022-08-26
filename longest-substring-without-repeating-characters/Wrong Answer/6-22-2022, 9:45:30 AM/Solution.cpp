// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left =0 ;
        int right =0 ;
        map <char ,int> m;
        int ans =0;
        while(right <n){
            char ch = s[right];
            if(m.count(ch)>0){
                left = m[ch]+1;
            }
            ans = max(ans ,right-left+1);
            m[ch]= right ;
            right ++;
        }
        return ans ;
    }
};