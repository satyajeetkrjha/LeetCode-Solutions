// https://leetcode.com/problems/valid-palindrome-iii

class Solution {
public:
    
    int cache[1001][1001];
    int longestpalindromic(string s ,int l,int r){
        if(l> r) return 0 ;
        if(l == r) return 1 ;
        if(cache[l][r])
            return cache[l][r];
        if(s[l] == s[r])
            return cache[l][r] = longestpalindromic(s,l+1,r-1)+2;
        return cache[l][r] = max(longestpalindromic(s,l+1,r),longestpalindromic(s,l,r-1));
        
    }
    
    
    bool isValidPalindrome(string s, int k) {
       
        memset(cache ,0,sizeof(cache));
        int ans = longestpalindromic(s,0,s.size()-1);
         return ans+k <= s.size() ? true:false;
    }
};