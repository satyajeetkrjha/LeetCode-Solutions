// https://leetcode.com/problems/valid-parentheses

#include <iostream>
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] =='(' || s[i] =='[' || s[i]=='{'){
                st.push(s[i]);
            }
           else {
               // u hae some ending bracket but u don't see any start left bracket as ur stack is empty so it's a false case
                if(st.empty()){
                   cout<<"false returned"<<endl;
                   return false;
               }
               
               if(!st.empty()){
                   char c= st.top();
                   st.pop();
                   cout<<"popped is "<<c<<endl;
                   if(s[i] ==')' && c !='('){
                       cout<<"s[i] "<< c<<endl;
                       return false;
                   }
                       
                   else if (s[i]== '}' && c!='{'){
                       cout<<"s[i] "<< c<<endl;
                        return false;
                   }
                      
                   else if(s[i] ==']' && c!='['){
                         cout<<"s[i] "<< c<<endl;
                    return false;   
                   }
                       
               }
              
                   
           }
        }
        return true && st.empty(); // stack should be empty at end of  all process or u got just one enclosing bracket
    }
};