// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        map <char ,int> m ;
        for(auto it :s){
            m[it]++;
        }
        for(auto it :goal){
            m[it]--;
        }
        for(auto it :m){
            if(it.second !=0){
                return false;
            }
        }
    return true ;        
        
    }
};