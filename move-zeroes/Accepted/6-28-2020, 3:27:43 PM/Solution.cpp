// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int c=0;
       int index =0;
       for(int i=0;i<nums.size();i++){
           if(nums[i] == 0){
               c++;
           }
           else{
                nums[index]=nums[i];
                index++;
           }
              
       }
     while(c>0){
         nums[index]=0;
         c--;
         index++;
     }
    }
};