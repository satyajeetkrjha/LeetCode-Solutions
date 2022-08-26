// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
    /*
    Rem that x ^(-3) is equiavalent to 1/(x^3))
    */
        int N = n;
        if(N <0){
            N = -n;
            x = 1/x;
        }
        
        double ans = 1;
        for(long long int i =0 ; i<N;i++){
            ans = ans * x;
        }
        return ans ;
        
        
        
        
    }
};