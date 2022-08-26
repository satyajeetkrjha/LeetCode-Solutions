// https://leetcode.com/problems/broken-calculator

class Solution {
public:
    int brokenCalc(int start, int target) {
    
        int steps =0 ;
        while(target >start){
            if(target % 2 == 1){
                target ++;
            }
            else {
                target/=2 ;
            }
            steps ++;
        }
        return steps + (start -target) ;
    }
};