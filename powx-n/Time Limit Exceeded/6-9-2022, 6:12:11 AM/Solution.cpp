// https://leetcode.com/problems/powx-n

typedef long long int ll ;
class Solution {
public:
    
    double calpow(double base ,ll power){
        if(power == 0)
            return 1.0;
        if(power %2 == 0)
           return calpow(base ,power/2)*calpow(base,power/2);
        else
            return calpow(base,power/2)*calpow(base,power/2)*base;
    }
    
    
    
    double myPow(double x, int n) {
        ll N =n;
        if(n <0){
            N= -N;
            x = 1/x;
        }
        
        double ans  = calpow(x,n);
        return ans ;
    }
};