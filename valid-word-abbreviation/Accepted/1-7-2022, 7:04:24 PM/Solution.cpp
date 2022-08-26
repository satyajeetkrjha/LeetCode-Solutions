// https://leetcode.com/problems/valid-word-abbreviation

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int a = 0 ;
        int w = 0 ;
        while(w < word.size() && a< abbr.size()){
           if(abbr[a] == '0'){
               return false;
           }
            
            int num =0;
            while(a< abbr.size() && isdigit(abbr[a])){
                num = num *10 + (abbr[a] -'0');
                a++;
            }
            if(num!=0){
                w = w+ num;
            }
            else{
                if(word[w]!=abbr[a]){
                    return false;
                }
                a++ ;
                w++;
            }
        }
        return w == word.size() && a == abbr.size();
        
    }
};