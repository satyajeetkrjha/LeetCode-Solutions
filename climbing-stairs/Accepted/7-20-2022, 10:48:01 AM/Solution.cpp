// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
       int first = 1 ;
       int second = 2;
        int third=0;
        if( n == 1)
            return first ;
        if(n == 2)
            return second ;
        for(int i = 3;i<= n;i++){
            third = first+ second ;
            first = second ;
            second = third;
            
        }
        
        return third;
        
    }
};