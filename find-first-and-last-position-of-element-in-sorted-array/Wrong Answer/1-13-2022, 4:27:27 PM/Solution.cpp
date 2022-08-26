// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int low =0 ;
       int high = nums.size()+2;
        int n = nums.size();
        vector<int> res;
       while(high-low>1){
           int mid =(low+high)/2;
           if(mid < n && nums[mid]<=target){
               low = mid;
           }
           else{
               high = mid;
           }
       } 
       int val = nums[low] == target ? low :-1;
       res.push_back(val);
        
        low = -1;
        high = nums.size()-1 ;
        while(high-low>1){
            int mid=(low+high)/2;
            if(mid <n && nums[mid]>=target){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        val = nums[high] == target ? high:-1;
        res.push_back(val);
       
        return res ;
        
        
    }
};