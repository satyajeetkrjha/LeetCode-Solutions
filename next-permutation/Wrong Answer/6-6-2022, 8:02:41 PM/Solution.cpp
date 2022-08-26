// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size()-1;
        n= n -1;
        
        int index =0 ;
        /*
        int k = n ;
        while(k >=0 && nums[k]>= nums[k+1]){
            k--;
        }
        index =k;
        */
        
        for(int i = n;i>=0 ;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        
        
        
        if(index >=0){
            for(int i = nums.size()-1;i>=index ;i--){
                if(nums[index]<nums[i]){
                    swap(nums[index],nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+index+1,nums.end());
        
        
    }
};