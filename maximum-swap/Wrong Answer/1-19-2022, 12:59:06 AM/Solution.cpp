// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    
    int maxdigit = -1 ;
    int leftindex = -1;
    int rightindex = -1;
    int maxindex = -1;
    
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i= s.size()-1 ;i>=0 ;i--){
            if(s[i] > maxdigit){
                maxdigit = s[i];
                maxindex = i ;
                continue ;
            }
            if(maxdigit > s[i]){
                leftindex = i ;
                rightindex = maxindex;
            }
            
        }
        if(leftindex == -1){
            return false;
        }
        swap(s[leftindex],s[rightindex]);
         return stoi(s);
    }
};