// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = goal+goal ;
        if(s.size()!= goal.size()){
            return false;
        }
        if(temp.find(s) >=0){
            return true;
        }
        return false;
    }
};