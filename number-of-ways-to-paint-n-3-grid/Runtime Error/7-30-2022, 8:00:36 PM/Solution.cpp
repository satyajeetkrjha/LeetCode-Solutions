// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    const int mod = (int)1e9+7;
    int numOfWays(int n) {
        int color3 = 6 ;
        int color2 = 6;
         for(int i =2 ;i<=n;i++){
             int tempcolor = color3;
             color3 = (2* color2 +2*color3 ) %mod;
             color2 = (2*tempcolor +3 *color2) %mod;
             
         }
        return (int)(color2+color3)% mod ;
    }
};