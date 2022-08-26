// https://leetcode.com/problems/valid-perfect-square

typedef long long int ll;
class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num ==1)
            return true;
        if(num <1)
            return false;
        ll low =1;
        ll high =num;
        while(low <=high){
            ll mid =low+(high-low)/2;
            if(mid*mid ==num){
                return true;
            }
            else if(mid*mid <num){
                low =mid+1;
            }
            else if(mid*mid>num){
                high =mid-1;
            }
        }
        return false;
    }
};