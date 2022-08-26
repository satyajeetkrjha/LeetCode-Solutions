// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans=1000000;
        for(int i=1;i< nums.size();i++){
            int diff =abs(nums[i]-nums[i-1]);
            ans =min(ans,diff)+1;
        }
        return ans;
    }
};