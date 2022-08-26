// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    bool palindrome (string s,int low ,int high){
        while(low <high){
            if(s[low]!=s[high]){
                return false;
            }
            low ++;high--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int ans =0;
        for(int low =0 ;low <s.size();low++){
            for(int high = low ;high <s.size();high++){
                if(palindrome(s,low,high)){
                    ans ++;
                }
            }
        }
        return ans ;
        
    }
};