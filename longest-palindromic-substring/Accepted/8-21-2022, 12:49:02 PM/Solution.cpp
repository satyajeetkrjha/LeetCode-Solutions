// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    
    int expandaroundcenter(string s ,int left ,int right){
        while(left <= right && left>=0 && right <=s.size()-1 && s[left] == s[right]){
            left --;
            right ++;
        }
        return right-left -1 ;
    }
    
    
    string longestPalindrome(string s) {
        int start =0 ;
        int maxlen =0;
        for(int i = 0 ;i<s.size();i++){
            int len1 = expandaroundcenter(s,i,i);
            int len2 = expandaroundcenter(s,i,i+1);
            int len = max(len1,len2);
            if(len >maxlen){
                maxlen = len ;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start ,maxlen);
    }
};