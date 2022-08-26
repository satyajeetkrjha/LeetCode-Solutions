// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int maxlen =0 ;
    int start = 0 ;int end =0 ;
    
    int expandaroundcenters(string s,int left ,int right){
        while(left >=0 && right<s.size() && s[left] == s[right]){
            left --;
            right ++;
        }
        return right - left -1;
    }
    string longestPalindrome(string s) {
        for(int i =0 ;i<s.size();i++){
            int len1 = expandaroundcenters(s,i,i);
            int len2 = expandaroundcenters(s,i,i+1);
            int len = max(len1,len2);
            if(len > (end-start)){
                start = i -(len-1)/2;
                end = i+(len/2);
                maxlen = max(maxlen ,len);
            }
        }
        return s.substr(start,maxlen);
        
      
    }
};