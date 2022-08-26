// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-2;
        int i = n ;
        int index =0 ;
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        index =i;
        int val =0;
        
        if(index>=0){
            for(int i = index+1 ;i<nums.size();i++){
                if(nums[i]> nums[index]){
                   val =i ;
                    swap(nums[index],nums[val]);
                    break;
                }
            }
        }
        
        reverse(nums.begin()+index+1 ,nums.end());
        
    }
};