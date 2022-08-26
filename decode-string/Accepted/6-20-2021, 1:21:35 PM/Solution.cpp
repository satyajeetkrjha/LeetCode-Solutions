// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack <char > stack;
        
        for(int i=0;i<s.size();i++){
            // super simple step
            if(s[i] != ']'){
                stack.push(s[i]);
            }
            else if (s[i] == ']'){
                // take out everything from stack now and add it to decoded string until you find an opening bracket
                string decodedstring ="";
                while(stack.top() != '['){
                  decodedstring +=stack.top();
                    stack.pop();
                }
                cout<<"decoded string is "<<decodedstring <<endl;
                // pop the opening bracket now as we find one opening bracket 
                stack.pop();
                // now we are sure to find digits so build the digit 
                
                int base =1;
                int k =0;
                
               
                while(!stack.empty() && isdigit(stack.top())){
                    k  = k+(stack.top()-'0')*base;
                    base = base*10;
                    stack.pop();
                }
                
                int len = decodedstring.size();
                
                while(k!=0){
                    for(int index = len -1;index >=0;index --){
                      stack.push(decodedstring[index]);
                    }
                    k--;
                }
            }
        }
        
        string result ;
        for(int i = stack.size() -1;i>=0;i--){
            result = stack.top()+result;
            stack.pop();
        }
    
        return result ;
        
        
    }
};