// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>= nums[i+1]){
            i--;
        }
        // now i stores the index where nums[i]<nums[i+1] because we came out of the loop
        int index = i ;
        cout <<"index is "<<index <<endl;
        if(index >=0){
            // find the first largest element on the right of this index
            int j = nums.size()-1;
            while(nums[index]>= nums[j]){
                j --;
            }
            // so when you move out of this loop our nums[i]< nums[j]
            swap (nums[index], nums[j]);   
        }
        reverse(nums.begin()+ index+1, nums.end());
         
    }
};