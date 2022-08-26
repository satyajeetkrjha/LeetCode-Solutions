// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        for(int i =0 ;i<s.size();i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res ;
        while(!st.empty()){
            res=st.top()+res;
            //cout<<"element is "<<st.top()<<endl;
            
            st.pop();
        }
        return res ;
    }
};