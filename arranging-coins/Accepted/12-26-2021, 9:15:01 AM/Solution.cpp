// https://leetcode.com/problems/arranging-coins

typedef long long int ll ;
class Solution {
public:
    int arrangeCoins(int n) {
        long long int ans = (sqrt((ll)2*n+0.25) -0.5);
        return ans ;
    }
};