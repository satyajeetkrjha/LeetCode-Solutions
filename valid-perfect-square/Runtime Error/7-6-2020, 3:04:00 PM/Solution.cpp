// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num ==1)
            return true;
        if(num <1)
            return false;
        int low =1;
        int high =num;
        while(low <=high){
            int mid =(low+high)/2;
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