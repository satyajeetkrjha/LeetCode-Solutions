// https://leetcode.com/problems/powx-n

typedef long long int ll;
class Solution {
public:
    double myPow(double x, int n) {
        ll N = n ;
        if(N <0){
            N= -N;
            x = 1/x;
        }
        
        double ans =1 ;
        for(int i =0;i<N;i++){
            ans = ans * x;
        }
        return ans ;  
    }
};