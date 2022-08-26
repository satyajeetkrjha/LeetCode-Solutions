// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        string s ="11";
        for(int i = 3;i<=n;i++){
            string t=" ";
            s = s+'$';
            int count = 1 ;
            for(int j =1 ;j< s.size();j++){
                if(s[j]!=s[j-1]){
                    t+=to_string(count);
                    t = t+s[j];
                    count =1 ;
                }
                else{
                    count ++;
                }
            }
            s = t ;
        }
        return s ;
    }
};