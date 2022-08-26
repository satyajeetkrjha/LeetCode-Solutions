// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int low=0;
      int high = nums.size()-1;
        int key =target;
      while(low <=high){
          int mid =(low+high)/2;
          if(nums[mid] == target) return mid;
          if(nums[low]<=nums[mid]){ // left half of nums[lows,......,mid] is sorted now so searh in this half
              if(key >=nums[low] && key <nums[mid]){ // we have out target in half [low,....mid] so reduce  your search 
                  high =mid-1;
              }
              else 
                  low =mid+1; // we didn't find elememt in  this sorted half [low.,,,mid] so now we need to search in [mid,.....,high]
               
          }
          else { // right half is sorted
              if(key >nums[mid] && key <=nums[high]){ // we got our tartget in second sorted haf
                  low =mid+1; 
              }
              else 
                  high =mid-1;
          }
      }
        return -1;
        
    }
};