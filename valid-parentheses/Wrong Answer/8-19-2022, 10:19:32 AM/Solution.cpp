// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
      stack <char> st ;
        if(s.size() == 1)
            return false;
      for(int i =0 ;i<s.size();i++){
          char ch = s[i];
          if(ch =='(' || ch =='{' || ch =='['){
              st.push(ch);
          }
          else {
              if(st.empty()){
                  return false;
              }
              char topchar = st.top();
              st.pop();
              if(ch == ')' && topchar !='('){
                  return false;
              }
              if(ch == '}' && topchar !='{'){
                  return false;
              }
              if(ch == ']' && topchar !='[' ){
                  return false;
              }
          }
      }
        return true ;
    }
};