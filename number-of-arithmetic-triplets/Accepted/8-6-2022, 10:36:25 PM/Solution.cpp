// https://leetcode.com/problems/number-of-arithmetic-triplets

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count =0;
        int k =0;
       for(int i =0 ;i<n;i++){
           for(int j = i+1;j<n;j++){
               for(int k = j+1 ;k<n;k++){
                   if(abs(nums[k]-nums[j]) == abs(nums[j]-nums[i]) && abs(nums[j]-nums[i]) == diff){
                   count ++;
               }
              }
           }
       }
        return count ;
    }
};