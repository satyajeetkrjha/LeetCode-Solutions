// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = goal+goal ;
        if(s.size()!= goal.size()){
            return false;
        }
        if(temp.find(s)!= string::npos){
            return true;
        }
        return false;
    }
};