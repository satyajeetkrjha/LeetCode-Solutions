// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack <char> st ;
        
        for(int i =0 ;i<s.size();i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch =='{'){
                st.push(ch);
            }
            else{
                /* we have a closing bracket and we see that stack is empty which basically means situatio is like )  or } or ] being pushed making it invalid */
                if(st.empty()) return false ;
                char topchar = st.top();
                st.pop();
                if(topchar == '(' && ch!=')'){
                    return false;
                }
                if(topchar =='[' && ch !=']'){
                    return false ;
                }
                if( topchar== '{' && ch!='}'){
                    return false;
                }        
                
            }
        }
        
        return st.empty() && true ;
        
    }
};