// https://leetcode.com/problems/longest-common-prefix

#include <iostream>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();// total number of words
        string firstWord =strs[0];
        string lcp="";
        
        for(int i=0;i<firstWord.length();i++){
            char c =firstWord[i];
            cout<<"c is"<<c<<endl;
            for(int j=1;j<n;j++){
                string word =strs[j];
                cout<<"word is "<<word<<endl;
                if(i> word.length() || word[i]!=c){
                    return lcp;
                }
            }
            
            lcp+=c;
            cout<<"lcp now is "<<lcp<<endl;
        }
        return lcp;
        
    }
};