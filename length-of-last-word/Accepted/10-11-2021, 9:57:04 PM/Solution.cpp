// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        bool charfound = false;
        int len =0;
        for(int i = n-1 ;i>=0 ;i--){
            if((s[i] >='a' || s[i]<'z' || s[i]>'A' || s[i]<'Z') && s[i] != ' '){
                charfound = true;
                len++;
               // cout<<"s[i] is "<< s[i]<< " ";
            }
            if( charfound  && s[i] == ' '){
                break;
            }
        
        }
        return len;
    }
};