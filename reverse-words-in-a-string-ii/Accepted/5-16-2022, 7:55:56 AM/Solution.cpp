// https://leetcode.com/problems/reverse-words-in-a-string-ii

class Solution {
public:
    void reverseWords(vector<char>& s) {
      reverse(s.begin(),s.end());
        int start =0;
        int end =0 ;
        int n = s.size();
        while(start <n){
            while(end <n && s[end]!=' '){
                end++;
            }
            // end has now reached that empty position 
            reverse(s.begin()+start ,s.begin()+end);
            end++;
            start = end ;
        }

    }
};