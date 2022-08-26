// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> nums1copy(nums1.size());
        
        for(int i =0 ;i<nums1.size();i++){
            nums1copy[i]= nums1[i];
        }
        
        int p1 = 0 ;int p2 =0;
        
        for(int i =0 ;i<m+n;i++){
            // p2?>= n means all nums2 elements exhausted
            if(p2 >=n || (p1<m && nums1copy[p1]<nums2[p2])){
                nums1[i] = nums1copy[p1++];
            }
            else {
                nums1[i]= nums2[p2++];
            }
        }
        
        
    }
};