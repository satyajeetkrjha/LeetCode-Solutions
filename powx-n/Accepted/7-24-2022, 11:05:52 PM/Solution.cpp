// https://leetcode.com/problems/powx-n

typedef long long int ll ;
class Solution {
public:
    
    
    double calpow(double base ,int power){
        if(power  == 0)
            return 1.0 ;
        double half = calpow(base ,power/2);
        if(power%2 == 0)
            return half*half;
        else
            return half*half*base ;
    }
    
    
    
    
    double myPow(double x, int n) {
      ll N = n ;
      if(N <0){
          N = -N ;
          x = 1/x ;
      }
        double ans = calpow(x,N);
        return ans ;
    }
};