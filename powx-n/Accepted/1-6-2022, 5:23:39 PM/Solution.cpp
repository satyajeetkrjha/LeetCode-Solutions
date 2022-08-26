// https://leetcode.com/problems/powx-n

typedef long long int ll;
class Solution {
public:
    
    double fastexp(double x ,int n){
        if(n ==0){
            return 1;
        }
        double half = fastexp(x ,n/2);
        if(n %2 ==0){
            return half*half;
        }
        return half*half*x;
    }
    
    
    
    double myPow(double x, int n) {
        ll N = n;
        if(n<0){
            N= -N;
            x = 1/x;
        }
        double ans =fastexp(x,N);
        return ans ;
        
    }
};