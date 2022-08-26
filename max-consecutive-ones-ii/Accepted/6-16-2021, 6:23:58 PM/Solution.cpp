// https://leetcode.com/problems/max-consecutive-ones-ii

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // sliding wimdow 
        int left =0;
        int right =0;
        int longestsequence =0;
        int numzeroes =0;
        while(right <nums.size()){
            if(nums[right] ==0 ){
                numzeroes++;
            }
            // invalid state so contract 
            // also think of this case 1 1 1 1 0 0 whete left is at index zero so you keep moving to left but you do not decrease number of zeroes
            while(numzeroes == 2){
                if(nums[left] == 0 ){
                    numzeroes --;
                }
                left++;
            }
            
            longestsequence = max(longestsequence ,right -left+1);
            right++;
        }
        return longestsequence ;
    }
      
};