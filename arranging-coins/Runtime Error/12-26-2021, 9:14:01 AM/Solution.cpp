// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        long long int ans = (sqrt(2*(n)+0.25) -0.5);
        return ans ;
    }
};