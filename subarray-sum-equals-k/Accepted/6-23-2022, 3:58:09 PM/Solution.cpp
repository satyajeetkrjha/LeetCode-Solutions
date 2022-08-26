// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
       int count =0 ;
       int cursum =0 ;
        map <int ,int> m;
        for(int i =0 ;i<nums.size();i++){
            cursum += nums[i];
            if(cursum == target){
                count++;
            }
            count += m[cursum-target];
            m[cursum]++;
        }
        return count ;
    }
};