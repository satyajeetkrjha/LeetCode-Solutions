// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int open = 1;
    int close = -1;
    int sum =0;
    int minAddToMakeValid(string s) {
        
        for(auto &ch:s){
            if(ch == '('){
            sum += open;
        }
          else{
            sum += close;
        }
    }
        return abs(sum);
        
    }
};