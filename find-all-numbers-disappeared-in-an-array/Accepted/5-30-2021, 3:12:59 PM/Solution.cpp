// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // bucket approach 
        vector<int > res;
        for(int i=0;i<nums.size();i++){
            int val = abs(nums[i]); // but for number ,we will mark 2 as negative as index strats for zero
            if(nums[val-1]>0){
                nums[val-1]*=-1;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(nums[i-1]>0){
                res.push_back(i);
            }
        }
        return res;
         
    }
};