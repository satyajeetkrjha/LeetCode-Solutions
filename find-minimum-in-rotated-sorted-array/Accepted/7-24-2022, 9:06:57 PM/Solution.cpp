// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
       int low = 0 ;
       int high = nums.size()-1;
       if(nums.size()  == 1)
           return nums[0];
        
        // this mean array is not rotated at all 
        if(nums[low]<nums[high]){
            return nums[low];
        }
        
        while(low <= high){
            int mid = (low+high)/2 ;
            if(nums[mid]> nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            // this part is sorted so inflection point is not in this part
            else if(nums[mid]<nums[high]){
                high = mid-1;
            }
            else if(nums[mid]>nums[low]){
                low = mid+1;
            }
        }
        return -1;
        
        
    }
};