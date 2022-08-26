// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int prevGC = 1;
        int currentGC= 0;
        int ans =0;
        for(int i =1 ;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans += min(prevGC,currentGC);
                prevGC = currentGC;
                currentGC = 1;
            }
            else{
                currentGC++;
            }
        }
        ans += min(prevGC,currentGC);
        return ans ;
    }
};