// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum =0;
        int totalsum =0;
        // We will maintain a running leftsum 
        for(int i =0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(totalsum -nums[i]-leftsum == leftsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};