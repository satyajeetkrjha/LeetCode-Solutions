// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0 ;
        int high = nums.size();
        while(low <= high){
            int mid =(low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){
                if(target <nums[mid] && target >= nums[low]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(target> nums[mid] && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
                
            }
        }
        return -1;
        
        
    }
};