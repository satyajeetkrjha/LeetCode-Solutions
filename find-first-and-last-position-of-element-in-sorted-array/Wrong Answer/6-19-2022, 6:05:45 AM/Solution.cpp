// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        
        if(nums.size() == 0 ){
            return {-1,-1};
        }
        int left =0 ;
        int right = nums.size()-1;
        
        int start = -1 ;
        while(left <=right){
            int mid = (left+right)/2;
            if(mid>0 && nums[mid] == target && nums[mid-1]!=target){
                start= mid;
                break;
            }
            else if(nums[mid]>=target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        int last = -1 ;
        left =0;
        right = nums.size() -1;
        while(left <= right){
            int mid =(left+right)/2 ;
            if(mid+1< nums.size() && nums[mid] == target && nums[mid+1]!=target){
                last = mid ;
                break;
            }
            else if(nums[mid] <= target){
                left = mid+1;
            }
            else {
                right = mid -1 ;
            }
        }
        return {start,last};
        
    }
};