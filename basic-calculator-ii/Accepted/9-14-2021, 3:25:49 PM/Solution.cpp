// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    int calculate(string s) {
      if(s.size() == 0)
          return 0;
       stack <int> st;
       char operation ='+';
       int currentnumber = 0 ;
       for(int i =0 ;i<s.size();i++){
           char currentcharacter = s[i];
           if(isdigit(currentcharacter)){
               currentnumber = (currentnumber*10) +(currentcharacter-'0');
           }
           if (!isdigit(currentcharacter) && !iswspace(currentcharacter) || i == s.size()-1){
               if(operation == '+'){
                   st.push(currentnumber);
               }
               else if(operation == '-'){
                   st.push(-currentnumber);
               }
               else if(operation == '*'){
                   int topval = st.top();
                   st.pop();
                   st.push(topval*currentnumber);
               }
               else if(operation == '/'){
                   int topval = st.top();
                   st.pop();
                   st.push(topval/currentnumber);
               }
               operation = currentcharacter;
               currentnumber =0;
           }    
    }
         int result = 0 ;
        while(st.size()!=0){
            result+= st.top();
            st.pop();
            
        }
                    return result ;
                    }
                    
};