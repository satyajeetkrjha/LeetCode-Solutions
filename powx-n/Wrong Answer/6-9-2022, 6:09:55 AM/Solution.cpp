// https://leetcode.com/problems/powx-n

typedef long long int ll ;
class Solution {
public:
    
    ll calpow(ll base ,ll power){
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
        
        ll ans  = calpow(x,n);
        return ans ;
    }
};