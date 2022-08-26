// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool isValid(string s,int l,int r){
        while(l<r){
            if(s[l]== s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
    
        int l =0;
        int r =s.size();
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                break;
            }
        }
        // we reached first point of conflict so now check if we can form the remaining middle string as palindrom by removing first or last
        return isValid(s,l+1,r) || isValid(s,l,r-1);
    }
};