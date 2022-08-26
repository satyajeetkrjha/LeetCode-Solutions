// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left =0 ;
        int right =0;
        int oddcount =0;
        int ans =0;
        while(left <=right){
            if(oddcount>=k){
                if(nums[left]%2==0){
                    oddcount --;
                }
                left++;
                
            }
            else{
                if(nums[left]%2 !=0){
                    oddcount++;
                    right++;
                }
                if(oddcount == k){
                   ans++; 
                }
            }
            
        }
        return ans ;
    }
};