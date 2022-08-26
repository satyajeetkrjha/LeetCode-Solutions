// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
     
        int n = num1.size()-1;
        int m = num2.size()-1;
        string res ;
        int sum =0 ;
        int carry =0 ;
        while(n>=0 || m >=0){
            int x = n >=0 ? num1[n]-'0':0;
            int y = m>=0 ? num2[m]-'0':0;
            sum = (x+y+carry)%10;
            res = to_string(sum) +res ; 
            carry = (carry+x+y)/10;
            n--;
            m--;
        }
        if(carry){
            res = to_string(carry)+ res ;
        }
        return res ;
        
    }
};