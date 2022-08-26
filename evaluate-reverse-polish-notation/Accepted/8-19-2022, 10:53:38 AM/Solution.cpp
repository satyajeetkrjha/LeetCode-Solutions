// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack <int> st;
      for(int i =0 ;i<tokens.size();i++){
          string ch = tokens[i];
          if(ch == "+" || ch == "*" || ch == "/" || ch == "-"){
              auto first = st.top();st.pop();
              auto second = st.top();st.pop();
              if(ch == "+") st.push(first+second);
              if(ch == "-") st.push(second-first);
              if(ch == "/") st.push(second/first);
              if(ch == "*") st.push(first*second);
           }
          else
              st.push(stoi(ch));
      }
        return st.top();
    }
};