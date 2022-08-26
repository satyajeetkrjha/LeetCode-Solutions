// https://leetcode.com/problems/ransom-note

class Solution {
public:
    
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> v(26);
      for(int i=0;i<ransomNote.size();i++){
          char c = ransomNote[i];
          v[c-'a']++;
          
      }
        for(int i=0;i<magazine.size();i++){
            char c =magazine[i];
            v[c-'a']--;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]>0){
                return false;
            }
        }
        return true ;
    }
};