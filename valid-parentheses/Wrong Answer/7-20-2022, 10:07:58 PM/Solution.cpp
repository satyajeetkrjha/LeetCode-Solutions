// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
         stack <char > st ;
        for(int i =0 ;i < s.size();i++){
            char c  = s[i];
            if(c == '(' || c =='['  || c  == '{'){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    
                    char topchar = st.top();
                    
                    if(s[i] ==')' && topchar == '('){
                        st.pop();
                    }
                    if(s[i] ==']' && topchar == '['){
                        st.pop();
                    }
                    if(s[i] == '}' && topchar == '{'){
                        st.pop();
                    }
                }
            }
        }
        cout << "st.size() "<<st.size()<< endl;
        return true && st.empty() ;
    }
};