// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        if( nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        
        int x = nums1.size();
        int y = nums2.size();
        
        
        int low = 0 ;
        int high = x;
        
        // max max min min
        while(low <= high){
            int partitionX = (low +high)/2;
            int partitionY = (x+ y+1)/2 - partitionX;
            
            
            int maxleftX = partitionX  ==0 ? INT_MIN: nums1[partitionX-1];
            int maxleftY = partitionY  == 0 ?INT_MIN:nums2[partitionY-1];
            
            int minrightX = partitionX == x ? INT_MAX: nums1[partitionX];
            int minrightY = partitionY == y ? INT_MAX : nums2[partitionY];
            
            if(maxleftX <= minrightY && maxleftY <= minrightX){
                if((x+y)% 2== 0){
                    return (double)(max(maxleftX,maxleftY)+min(minrightX,minrightY))/2;
                }
                else{
                    return (double)max(maxleftX,maxleftY);
                }
            }
            else if(maxleftX > minrightY){
                high = partitionX-1;
            }
            else{
                low = partitionX+1;
            }   
        }
   return -1.0;        
        
    }
};