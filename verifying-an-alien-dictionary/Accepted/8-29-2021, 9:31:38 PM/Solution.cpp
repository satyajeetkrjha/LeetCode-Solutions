// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int orderMap[26]={0};
        for(int i =0 ;i<order.size();i++){
            char c = order[i];
            orderMap[c-'a']=i;
        }
        
       
        for(int i =0 ;i<words.size()-1;i++){
            for(int j =0 ;j<words[i].size();j++){
              if(j >= words[i+1].size()){
                  return false ;
              }
              string first = words[i];
              string second = words[i+1];
              if(first[j]!=second[j]){
                  int currentWordChar = first[j]-'a';
                  int nextWordChar = second[j]-'a';
                  if(orderMap[currentWordChar]>orderMap[nextWordChar]){
                      return false;
                  }
                  else
                      break;
                  
              }  
            }
        }
        
        return true ;
        
    }
};