// https://leetcode.com/problems/happy-number

class Solution {
public:
    int getnext(int n){
        int totalsum =0;
        while(n >0){
            int r = n%10;
            n = n/10;
            totalsum +=(r*r);
            
        }
        return totalsum;
    }
    bool isHappy(int n) {
        int slow = n ;
        int fast= getnext(n);
        while(fast!=1 && slow !=fast){
            slow = getnext(slow);
            fast = getnext(getnext(fast));
        }
        return fast == 1;
    }
};