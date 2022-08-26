// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence

class Solution {
public:
    bool areNumbersAscending(string s) {
       
        int cur =0;
        int prev =0;
        for(auto ch :s){
            if(isdigit(ch)){
                cur = cur*10+ (ch-'0');
            }
            else if(cur!=0){
                if(prev >= cur){
                    return false;
                }
                prev = cur ;
                cur =0;
            }
        }
         return cur > prev  || cur == 0 ;
        
        
        
        
    }
};