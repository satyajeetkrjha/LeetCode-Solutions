// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        
        stack <char > st ;
        for(int i =0 ;i<s.size();i++){
            char c = s[i];
            if(c !=']'){
                st.push(c);
            }
            else {
                
                string decodedstring;
                while(st.top()!='['){
                    char ch= st.top();
                    st.pop();
                    decodedstring += ch;
                }
                // now pop the opening bracket 
                st.pop();
                
                // make the number 
                int base =1 ;
                int num =0;
                
                while(!st.empty() && isdigit(st.top())){
                    num =  num+ (st.top()-'0')*base;
                    st.pop();
                    base = base *10;
                }
                
                /*
                    num stores the number and decoded string is our string we have to repeat
                    */
                int len = decodedstring.size() -1 ;
                while(num >0){
                    for(int i  = len ;i>=0 ;i--){
                        st.push(decodedstring[i]);
                    }
                    num --;
                }   
            }
        }
        
        string res ;
        int sz = st.size();
        for(int i =0 ;i<sz;i++){
            char c = st.top();
            st.pop();
            res = c+res;
        }
        return res ;
        
      
        
        
        
    }
};