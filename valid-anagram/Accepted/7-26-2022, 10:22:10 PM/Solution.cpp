// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
       vector <int> freq;
        freq.resize(26,0);
        if(s.size()!=t.size())
            return false;
        for(int i =0 ;i<s.size();i++){
            char ch1 = s[i];
            char ch2 = t[i];
            freq[ch1-'a']++;
            freq[ch2-'a']--;
        }
        
        for(int i =0 ;i<26;i++){
            if(freq[i]!=0)
                return false ;
        }
        return true ;
    }
};