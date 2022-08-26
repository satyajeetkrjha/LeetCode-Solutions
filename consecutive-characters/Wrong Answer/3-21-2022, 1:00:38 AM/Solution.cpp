// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int ans =0;
    int maxPower(string s) {
        
        int prev = s[0];
        int count =1 ;
        for(int i =1 ;i<s.size();i++){
            if(s[i] == prev){
                count++;
            }
            else{
                count =1;
            }
            ans = max(ans,count);
            prev = s[i];
        }
        return ans ;
    }
};