// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int leftbound = s.size();
        int rightbound = t.size();
        int left =0 ;
        int right =0;
        while(left <leftbound && right <rightbound){
            if(s[left] == t[right]){
                left++;
            }
            right++;
        }
        return left == leftbound ;
    }
};