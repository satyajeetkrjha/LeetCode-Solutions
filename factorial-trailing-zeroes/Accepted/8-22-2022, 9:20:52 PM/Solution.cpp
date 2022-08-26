// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int zerocount =0;
        int cur = 5 ;
        while(n>=cur){
            zerocount+= n/cur;
            cur = cur*5;
        }
        return zerocount ;
    }
};