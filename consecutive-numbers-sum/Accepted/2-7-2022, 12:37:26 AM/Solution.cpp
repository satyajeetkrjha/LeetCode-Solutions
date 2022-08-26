// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
       
        int ans =0;
        for(int k = 2 ;k<=sqrt(2*N);k++){
            if(((N- (k*(k-1)/2)))%k ==0){
                ans ++;
            }
        }
        return ans+1;
    }
};