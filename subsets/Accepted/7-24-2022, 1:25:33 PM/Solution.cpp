// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int> > res ;
    
    void backtrack(vector <int> &nums,int start ,vector<int>&temp){
        res.push_back(temp);
        for(int i = start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp);
            temp.pop_back();
        }
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> temp;
        backtrack(nums,0,temp);
        return res ;
    }
};