// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
     
        int sign = 1 ;
        int result = 0 ;
        int index = 0;
        int n = s.size();
        
        // first discard all spaces in beginning 
        while(index < n && s[index]==' '){
            index++;
        }
        
        if(index <n && s[index]=='+'){
            sign=1;
            index++;
        }
        else if(index <n && s[index] == '-'){
            sign =-1;
            index++;
        }
        
        while(index <n && isdigit(s[index])){
            int digit = s[index]-'0';
            
            if((result > INT_MAX/10) || (result == INT_MAX/10 && digit > INT_MAX%10)){
                return sign == 1? INT_MAX:INT_MIN;
            }
               result = result*10+ digit;
               index++;
        }
               
               return sign*result ;
        
        
        
    }
};