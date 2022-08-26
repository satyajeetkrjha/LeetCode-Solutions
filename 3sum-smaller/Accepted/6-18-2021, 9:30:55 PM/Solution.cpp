// https://leetcode.com/problems/3sum-smaller

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int ans =0;
      int n = nums.size();
      for(int i=0;i<nums.size();i++){
         // i is the first index and keep it fixed and play with l and r 
          // then increment i again and again play with l and r
          // also think about r-l as ans why ?
          int l =i+1;
          int r= n-1;
          while(l<r){
              if(nums[i]+nums[l]+nums[r]<target){
                  ans+=r-l;
                  l++;
              }
              else {
                  r--;
              }
          }
      }
        return ans;
    }
};