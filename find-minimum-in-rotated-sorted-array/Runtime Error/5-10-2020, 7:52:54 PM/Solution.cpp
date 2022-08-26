// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low =0;
        int ans;
        int high =n-1;
        if (n==1)
            return nums[0];
        while(low<=high){
            int mid =(low+high)/2;
            if(nums[mid]<nums[mid-1]){
                ans= nums[mid];
                break;
            }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    
};