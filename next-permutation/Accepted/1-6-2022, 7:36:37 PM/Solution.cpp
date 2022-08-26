// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
       // .......4 9 8 7 6 
        
        int n = nums.size() -1;
        n--;
        int index =0;
        int i = n ;
        while(i >=0 && nums[i]>= nums[i+1]){
            i--;
        }
        index = i;
        if(index>=0){
             for(int i = nums.size()-1 ;i>=index ;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
          }
        }
       
        reverse(nums.begin()+index+1,nums.end());
       
        
        
        
        
    }
};