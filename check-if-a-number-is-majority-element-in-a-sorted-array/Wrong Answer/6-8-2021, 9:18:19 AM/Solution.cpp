// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array

class Solution {
public:
    int firstoccurence(vector <int> &nums,int target){
        int ans =-1;
        int low =0;
        int high = nums.size()-1;
        while(low <=high){
            int mid =(low +high)/2;
            if(nums[mid]<target){
                low =mid+1;
            }
            else if(nums[mid]>target){
                high =mid -1;
            }
            else if( nums[mid] == target){
                ans =mid;
                high =mid -1;
            }
        }
        return ans ;
    }
    int lastoccurence(vector <int> & nums ,int target){
         int ans =-1;
        int low =0;
        int high = nums.size()-1;
        while(low <=high){
            int mid =(low +high)/2;
            if(nums[mid]<target){
                low =mid+1;
            }
            else if(nums[mid]>target){
                high =mid -1;
            }
            else if( nums[mid] == target){
                ans =mid;
                low =mid+1;
            }
        }
        return ans ;
    }
    
    bool isMajorityElement(vector<int>& nums, int target) {
        //find first occurence and last occurence using binary serach varinat 
        int index1 = firstoccurence(nums,target);
        int index2 =lastoccurence(nums,target);
        int n =nums.size();
        if((index2-index1+1)> n/2)
        return true;
        else
            return false ;
    }
};