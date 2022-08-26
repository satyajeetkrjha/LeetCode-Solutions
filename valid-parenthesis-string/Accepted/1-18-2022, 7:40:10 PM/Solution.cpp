// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
      int cmin = 0 ;
      int cmax = 0 ;
      
        for(int i =0 ;i<s.size();i++){
            char ch = s[i];
            if(ch =='('){
                cmin++;
                cmax++;
            }
            else if( ch ==')'){
                cmin --;
                cmax--;
            }
            else if (ch =='*'){
                cmax ++;
                cmin--;
                
            }
            if(cmax <0) return false;
            cmin = max(cmin ,0);
        }
        return cmin == 0;
        
    }
};