// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st ;
        for(auto s : tokens){
            if(s == "+" || s== "-" || s== "*" || s== "/"){
                int y =st.top();
                st.pop();
                int x = st.top();
                st.pop();
                if(s == "+") st.push(x+y);
                if(s == "-") st.push(x-y);
                if(s == "*") st.push(x*y);
                if(s == "/") st.push(x/y);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};