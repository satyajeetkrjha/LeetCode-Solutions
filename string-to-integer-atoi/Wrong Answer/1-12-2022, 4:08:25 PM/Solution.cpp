// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int res = 0 ;
        int sign =1;
        int n = s.size();
        int index = 0 ;
        while(index < n && s[index] == ' '){
            index++;
        }
        
        if(s[index] == '+' && index<n){
            sign =1;
            index++;
        }
        else if(s[index]=='-' && index<n){
            sign = -1;
            index++;
        }
        
        while(index <n && isdigit(s[index])){
            int digit = s[index]-'0';
            if(res > INT_MAX/10 || (res == INT_MAX/10 && digit>INT_MAX%10)){
                return sign ==1 ? INT_MAX:INT_MIN;
            }
            res = res*10+digit;
            index++;
        }
        return res ;
        
    }
};