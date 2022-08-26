// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    
    
    int expandaroundcenter(string s,int left ,int right){
        
        while(left>=0 && right <= s.size()-1 && left <= right && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left -1;
        
    }
    
    
    
    string longestPalindrome(string s) {
        int maxlen =0 ;
        int start =0;
        for(int i =0 ;i<s.size();i++){
            int len1 = expandaroundcenter(s,i,i);
            int len2 = expandaroundcenter(s,i,i+1);
            int len = max(len1,len2);
            if(len >maxlen){
                maxlen = len;
                start = i - (len-1)/2;
                
            }
            
        }
        cout <<"start is "<<start << endl;
        cout <<"maxlen is "<<maxlen << endl;
        return s.substr(start ,maxlen);
    }
};