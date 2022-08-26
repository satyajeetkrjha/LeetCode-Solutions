// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int acount =0;
        int bcount = 0;
       for(int i =1 ;i<n-1;i++){
           if(colors[i] == 'A' &&colors[i-1] == 'A' && colors[i+1] =='A')
               acount++;
           else if(colors[i] == 'B' && colors[i-1]=='B' && colors[i+1]=='B')
               bcount++;
       } 
        return acount > bcount ? true:false;
    }
};