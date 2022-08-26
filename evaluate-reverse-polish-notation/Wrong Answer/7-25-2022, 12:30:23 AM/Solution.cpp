// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:

    stack <int> st;
    int evalRPN(vector<string>& tokens) {
        for(auto &it: tokens){
            if(it == "*" || it == "+" || it == "/" || it == "-"){
                auto x = st.top() ;st.pop();
                auto y = st.top();st.pop();
                
                if(it == "+") st.push(x+y);
                if(it == "-") st.push(x-y);
                if(it == "/") st.push(x/y);
                if(it == "*") st.push(x*y);
            }
            else{
                st.push(stoi(it));
            }
        }
        
        return st.top();
    }
};