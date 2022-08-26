// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()+2;
        int sz = nums.size();
        while(high -low >1){
            int mid =(low+high)/2;
            if(mid<sz && nums[mid] <= target){
                low = mid;
            }
            else{
                high = mid ;
            }
        }
        return nums[low] == target ? low :-1;
    }
};