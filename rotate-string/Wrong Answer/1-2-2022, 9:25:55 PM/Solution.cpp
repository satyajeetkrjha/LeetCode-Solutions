// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = goal+goal ;
        if(goal.find(temp) >0){
            return true;
        }
        return false;
    }
};