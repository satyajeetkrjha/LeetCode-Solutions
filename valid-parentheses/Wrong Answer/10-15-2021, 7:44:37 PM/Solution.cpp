// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
      stack <char > st ;
      for(int i =0 ;i<s.size();i++){
          if(s[i] =='(' || s[i] =='[' || s[i]=='{'){
              st.push(s[i]);
          }
          else{
              if(st.empty()){
                  return true;
              }
              else{
                  char c = st.top();
                  st.pop();
                  if(c =='(' && s[i]!=')'){
                      return false;
                  }
                  if( c =='{' && s[i]!='}'){
                      return false;
                  }
                  if( c == '[' && s[i]!=']'){
                      return false;
                  }
              }
          }
      }
        return true && st.empty();
    }
};