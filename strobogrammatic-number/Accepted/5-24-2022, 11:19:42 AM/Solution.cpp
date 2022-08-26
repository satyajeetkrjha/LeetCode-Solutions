// https://leetcode.com/problems/strobogrammatic-number

class Solution {
public:
    bool isStrobogrammatic(string num) {
        map <char,char> m;
        m['1'] = '1' ;
        m['9'] = '6';
        m['6'] = '9';
        m['8'] = '8';
        m['0'] ='0';
        
        string res ;
        for(int i = num.size()-1;i>=0 ;i--){
            char c = num[i];
            if(m.count(c) == 0){
                return false;
            }
            res +=m[c];
        }
        return res == num ? true :false;
        
    }
};