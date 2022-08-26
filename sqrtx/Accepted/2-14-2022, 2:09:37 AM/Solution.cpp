// https://leetcode.com/problems/sqrtx

typedef long long int ll;
class Solution {
public:
    int mySqrt(int x) {
        if(x <2){
            return x ;
        }
        int left =2 ;
        int right = x/2;
        int pivot ;
        while(left <= right){
            pivot = left+(right-left)/2;
            ll num = (ll)pivot*(ll)pivot ;
            if(num > x){
                right = pivot-1;
            }
            else if(num < x){
                left = pivot+1;
            }
            else{
                return pivot;
            }
        }
        return right ;
    }
};