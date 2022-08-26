// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
       int freq[26];
        memset(freq,0,sizeof(freq));
       for(int i =0 ;i<s.size();i++){
           char ch1 = s[i];
           char ch2 = t[i];
           freq[ch1-'a']++;
           freq[ch2-'a']--;
       } 
        
        for(int i =0 ;i<26;i++){
            cout << freq[i]<< " ";
        }
        cout << endl;
        
        for(int i =0 ;i< 26;i++){
            if(freq[i] >0)
                return false ;
        }
        return true ;
    }
};