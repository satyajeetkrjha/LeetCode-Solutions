// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int maxval =0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] ==1){
                sum++;
            }
            else if (nums[i]  ==0 ){
                sum =0;
            }
            maxval = max(maxval ,sum);
        
        
        }
        return maxval;
    }
};