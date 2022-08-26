// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char > st ;
        st.push(s[0]);
        for(int i =1;i<s.size();i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        
        string res ;
        while(!st.empty()){
            res = st.top()+ res;
            st.pop();
        }
        return res ;
    }
};