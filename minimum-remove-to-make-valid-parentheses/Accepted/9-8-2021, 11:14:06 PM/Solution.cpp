// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> st;
        set <int> removableindices ;
        for(int i =0 ;i<s.size();i++){
            char c= s[i];
            if( c == '('){ // if it an opening bracket then just push it's index
                st.push(i);
            }
            else if ( c == ')'){
                
                
                if(st.empty()){
                    // stack is empty so just push this problematic index into removableindices vector
                    removableindices.insert(i);
                }
                else {
// if stack has an index it means there is one opening inside it so just pop that index
                    st.pop();
                }
            }
        }
        
        // if stack is not empty it means there were some opening indexs that didn't find a closing index so push them into removable indices vector
        while(!st.empty()){
            removableindices.insert(st.top());
            st.pop();
        }
        
        string ans;
        for(int i =0 ;i<s.size();i++){
            if(removableindices.find(i) == removableindices.end()){
                ans+=s[i];
            }
            
        }
        return ans ;
        
           
    
        
    }
};