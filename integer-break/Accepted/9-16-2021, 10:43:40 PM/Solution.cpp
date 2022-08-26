// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
      if(n == 3) return 2 ;
      if(n == 2) return 1;
      int product =1;
      while(n>4){
          product = product * 3;
          n = n-3;
      }
        product = product* n;
        return product;
    }
};