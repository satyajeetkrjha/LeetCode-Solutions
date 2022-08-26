// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int sz = min(word1.size(),word2.size());
        int n= word1.size();int m = word2.size();
        string ans ="";
        for(int i =0 ;i<sz;i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(n> sz){
            for(int i =sz;i<n;i++){
                ans+=word1[i];
            }
        }
            else{
                for(int i = sz;i<m;i++){
                    ans+=word2[i];
                }
            }
        
        return ans ;
      
    }
};