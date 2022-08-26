// https://leetcode.com/problems/powx-n

typedef long long int ll;
class Solution {
public:
    
    double exp(double x ,ll n){
        if(n == 0)
            return 1.0 ;
        double half = exp(x ,n/2);
        if(n%2 ==0){
            return half*half;
        }
        return half*half*x;
    }
    
    
    
    double myPow(double x, int n) {
        ll N = n ;
        if(n <0){
            N = -n ;
            x = 1/x;
        }
        double ans = exp(x,N);
        return ans;
    }
};