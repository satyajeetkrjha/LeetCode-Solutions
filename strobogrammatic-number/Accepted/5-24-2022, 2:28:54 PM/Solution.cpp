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
        
       int left =0;
        int right = num.size() -1;
        while(left <= right){
            
            if(m.find(num[left]) == m.end() || m[num[left]]!=num[right]){
                return false;
            }
            left++;
            right--;
        }
        return true ;
        
    }
};