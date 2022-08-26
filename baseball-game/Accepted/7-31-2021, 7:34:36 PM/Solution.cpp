// https://leetcode.com/problems/baseball-game


#include <string>
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack <int> s;
        for(int i =0 ;i<ops.size();i++){
            string val = ops[i];
            if(val == "C"){
                s.pop();
            }
            else if ( val == "D"){
                int num = s.top();
                s.push(num*2);
            }
            else if(val == "+"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int sum = num1+ num2;
                s.push(num2);s.push(num1);s.push(sum);
            }
            else {
               s.push(stoi(val));
            }
            
        }
        int ans = 0 ;
        while(!s.empty()){
            int num = s.top();
            cout<<"num is"<<num<<endl;
            ans+= num;
            s.pop();
        }
        return ans ;
        
    }
};