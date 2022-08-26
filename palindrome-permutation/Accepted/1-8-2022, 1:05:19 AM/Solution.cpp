// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    map <char ,int> m;
    bool canPermutePalindrome(string s) {
        for(int i =0 ;i<s.size();i++){
            m[s[i]]++;
        }
        int count = 0 ;
        for(auto it : m){
            count = count +(it.second)%2;
        }
        if(count <=1){
            return true;
        }
        return false;
        
    }
};