// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        
        if( x< 0 || (x% 10 == 0 && x!=0)){
            return 0;
        }
        
        int revertednum =0 ;
        while( x> revertednum){
            revertednum = revertednum*10 +(x%10);
            x = x/10;
        }
        
        return x == revertednum || x == revertednum/10;
        
    }
};