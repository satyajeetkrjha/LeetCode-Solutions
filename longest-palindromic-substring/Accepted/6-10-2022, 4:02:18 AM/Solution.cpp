// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    
    
    int maxlenfun(string s ,int left ,int right){
        
        while(left >=0 && right <=s.size()-1 &&  left <= right && s[right] == s[left]){
            left --;
            right++;
        }
        return right - left -1; // why ? because u subtract those two extra chars 
        
    }
    
    
    
    
    string longestPalindrome(string s) {
        int start =0 ;
        int maxlen =0;
        for(int i =0;i < s.size();i++){
            int len1 = maxlenfun(s,i,i); // odd length palindrome
            int len2 = maxlenfun(s,i,i+1) ; // even lenbth palindrome 
            int len = max(len1,len2);
            if(len > maxlen){
                start = i -(len-1)/2;
                maxlen = max(maxlen,len);
                
            }
        }
        return s.substr(start ,maxlen);
    }
};