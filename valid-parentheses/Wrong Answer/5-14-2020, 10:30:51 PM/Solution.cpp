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
        return true;
    }
};