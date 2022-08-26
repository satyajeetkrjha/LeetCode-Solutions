// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map <char ,int> m;
        for(int i =0;i<s.size();i++){
            m[s[i]]++;
        }
        int count =0;
        map <char,int>::iterator it ;
        for(it = m.begin();it!=m.end();it++){
            count+= (it->second %2);
        }
       if( count <=1 ){
           return true;
       }
        return false ;
    }
};