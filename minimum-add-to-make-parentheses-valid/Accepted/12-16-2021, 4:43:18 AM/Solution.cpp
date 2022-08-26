// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res =0 ;
        int open =0;
        for(int i =0;i<s.size();i++){
            if(s[i] == '('){
                open++;
            }
            else{
                if(open ==0){
                    res++;
                }
                else{
                    open --;
                }
            }
        }
        return res + open ;
    }
};