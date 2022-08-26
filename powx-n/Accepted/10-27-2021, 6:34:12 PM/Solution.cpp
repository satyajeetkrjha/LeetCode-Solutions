// https://leetcode.com/problems/powx-n

typedef long long int ll ;
class Solution {
public:
    double fastpow(double x ,ll n){
        if(n ==0)
            return 1;
        double half = fastpow(x,n/2);
        if(n%2 ==0){
            return half *half;
        }
        else{
            return half*half* x;
        }
    }
    double myPow(double x, int n) {
        ll N =n;
        if(N <0){
            N = -N;
            x = 1/x;
        }
        return fastpow(x,N);
    }
};