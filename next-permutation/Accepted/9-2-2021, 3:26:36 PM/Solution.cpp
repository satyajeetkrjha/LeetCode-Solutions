// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size()-2;
        int i = n ;
        while(i >=0 && nums[i] >= nums[i+1]){
            i-- ;
        }
        int index = i ;
        if(index >= 0){
            int val= nums.size()-1;
            while(nums[index]>= nums[val]){
                val --;
            }
            swap (nums[index], nums[val]);
            
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};