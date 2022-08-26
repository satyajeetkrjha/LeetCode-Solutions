// https://leetcode.com/problems/happy-number

class Solution {
public:
    int getNext(int n){
        int sum =0 ;
        while(n>0){
            int r = n%10;
            sum +=(r*r);
            n = n/10;
        }
        return sum ;
    }
    bool isHappy(int n) {
        int slow = getNext(n);
        int fast = getNext(getNext(n));
        while(slow!=fast && fast!=1){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};