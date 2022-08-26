// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int count =0;
    int ans =0;
    int minAddToMakeValid(string s) {
        for(auto &ch:s){
            if(ch == '('){
                count ++;
            }
            else if(ch == ')'){
                count --;
            }
            
            if(count <0){
                ans ++;
                count =0;
            }
        }
        return ans + count ;
    }
};