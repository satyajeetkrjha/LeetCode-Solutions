// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0 ;
        int high = nums.size() -1 ;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid ;
            }
            else if (nums[low]<nums[mid]){
                // [low .....mid] is sorted portion
                if(target >= nums[low] && target <nums[mid]){
                    high = mid-1;
                }
                else
                    low = mid+1; // target is in another sorted half 
            }
            else{
                
                if(target > nums[mid] && target <nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid -1;
                }
                
            }
        }
        return -1;
        
        
        
        
    }
};