// https://leetcode.com/problems/maximum-score-of-spliced-array

class Solution {
public:
    
    int sum1 =0 ;
    int sum2 =0;
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i =0 ;i<nums1.size();i++){
            sum1+= nums1[i];
            sum2+= nums2[i];
        }
        
        int max1 ,max2 ,first,second ;
        max1=max2=first=second =0;
        
        for(int i =0 ;i<nums1.size();i++){
            first+=(nums2[i]-nums1[i]); // we will add this to sum1 to maximize
            second+=(nums1[i]-nums2[i]); // add to sum2 to maximize
            
            
            max1= max(max1,first);
            max2 = max(max2,second);
            
            // typical kadane algo step
            if(first <0) first =0 ;
            if(second <0) second =0;
        }
        
        return max((max1+sum1),(max2+sum2));
        
        
    }
};