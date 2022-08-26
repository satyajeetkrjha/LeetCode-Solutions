// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()+2;
        while(high -low >1){
            int mid =(low+high)/2;
            if(nums[mid] == target){
                low = mid;
            }
            else{
                high = mid ;
            }
        }
        return low ;
    }
};