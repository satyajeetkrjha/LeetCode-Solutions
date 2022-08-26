// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0 ;
        int flip =0;
        int cost =INT_MAX;
        for(int i =0 ;i<s.size();i++){
            if(s[i] == '1'){
                ones ++;
            }
            else{
                flip++;
            }
            flip = min(flip,ones);
        }
        return flip ;
    }
};