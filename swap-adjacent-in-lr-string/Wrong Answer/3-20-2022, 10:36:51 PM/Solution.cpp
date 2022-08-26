// https://leetcode.com/problems/swap-adjacent-in-lr-string

class Solution {
public:
    bool canTransform(string start, string end) {
        int si=0 ;
        int ei =0 ;
        while(si < start.size() && ei < end.size()){
            while(si < start.size() && start[si] == 'X') si++;
            while(ei< end.size() && end[ei] == 'X') ei++;
            if(start[si] !=end[ei]){
                return false ;
            }
            if(start[si] == 'R' && si > ei){
                return false;
            }
            if(start[si] == 'L' && si < ei){
                return false;
            }
            
            si++;
            ei++;
        }
        return true ;
    }
};