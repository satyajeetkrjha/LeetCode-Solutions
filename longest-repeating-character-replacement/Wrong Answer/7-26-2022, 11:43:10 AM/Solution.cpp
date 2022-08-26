// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left =0 ;
        int right =0 ;
        int res = 0 ;
        map <char ,int> m;
        while(right <s.size()){
            m[s[right]]++;
            int maxOccurence =INT_MIN;
            for(auto &it:m){
                maxOccurence = max(maxOccurence,it.second);
            }
            while(((right-left+1) -maxOccurence) >k){
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res ;
    }
};