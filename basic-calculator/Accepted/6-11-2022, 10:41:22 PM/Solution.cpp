// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s) {
        int sum =0 ;
        int sign = 1 ;
        stack <int> st ;
        for(int i =0 ;i< s.size();i++){
            char ch = s[i];
            if(ch == '-'){
                sign =  -1;
            }
            else if (isdigit(ch)){
                int val =0 ;
                while(i<s.size() && isdigit(s[i])){
                    val = val *10 + (s[i]-'0');
                    i++;
                }
                i--;
                val = val *sign ;
                sign =1 ;
                sum = sum + val;
            }
            else if(ch == '('){
                st.push(sum);
                st.push(sign);
                sum =0 ;
                sign =1 ;
            }
            else if(ch == ')'){
                sum = sum *st.top();st.pop();
                sum = sum + st.top();st.pop();
                
            }
        }
        return sum ;
    }
    
};