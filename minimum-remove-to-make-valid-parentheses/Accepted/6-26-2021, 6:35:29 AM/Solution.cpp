// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set <int > removableindices; // this contains all the indices that we need to remove
        stack <int> st;
        string ans;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if( c == '('){ // opening bracket so push this to stack
                st.push(i);
            }
            else if(s[i] == ')') {
               // two cases ,one is that stack is empty and u see closing bracket so remove
                if(st.empty()){
                    removableindices.insert(i);
                }
                else {
                    st.pop(); // an opening bracket found so pop it
                }
            }
        }
        
        // if you still have non empty stack it means it contains more opening brackets than closing brackets so they are problematic index
        while(!st.empty()){
            removableindices.insert(st.top());
            st.pop();
        }
        for(int i =0 ;i<s.size();i++){
            if(removableindices.find(i) != removableindices.end()){
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        return ans ;
        
    }
};