// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() ==1)
            return nums[0];
        
        int low = 0 ;
        int high = nums.size() -1 ;
        // when array is not rotated at all
        if(nums[0] < nums[high]){
            return nums[0];
        }
        
        
        while(low<=high){
            int mid = (low+high)/2 ;
            // because mid is the point of change
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            
            // mid -1 is point of change
            else if(nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid]>nums[0]){
                low = mid+1;
            }
            else if(nums[mid]<nums[high]){
                high = mid-1;
            }
            
        }
        return  -1;
        
        
    }
};