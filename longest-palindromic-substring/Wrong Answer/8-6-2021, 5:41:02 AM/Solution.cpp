// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int palindromelength(string s,int left,int right){
          int l = left;int r = right ;
          // now start expanding 
          
          while(l>=0 && r<s.size() && s[l] == s[r]){
              l--;// go more left
              r++; // go  more right
          }
          return r-l-1;
          
      }  
        
        
    string longestPalindrome(string s) {
        
        string ans ="";
        int n = s.size();
        int start =0 ;int end =0;
        for(int i =0 ;i<n;i++){
            // two possible cases where a single letter is the centre of the string 
            int len1 = palindromelength(s,i ,i);
            // second possibility where two letters are the centre of the string 
            int len2 = palindromelength(s,i,i+1);
            int len = max(len1,len2);
            if(len > end-start){
                start = i -(len-1)/2;
                end = i+ len/2;
            }
        }
         return s.substr(start,end);   
    }
};