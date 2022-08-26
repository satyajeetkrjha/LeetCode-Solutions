// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector <int> freq1(26,0);
        vector <int> freq2(26,0);
        if(word1.length() != word2.length()){
            return false;
        }
        for(int i=0;i<word1.length();i++){
            freq1[word1[i]-'a']++;
        }
        for(int j=0;j<word2.length();j++){
            if(freq1[word2[j]-'a'] ==0){
                return false;
            }
            freq2[word2[j]-'a']++;
        }
        sort(freq1.begin() ,freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1 == freq2;
    }
};