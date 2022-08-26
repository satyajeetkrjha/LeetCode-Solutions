// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    
    void backtrack(vector<int> &nums,vector <vector <int> > &res,vector<int>&temp,int start,int remain){
        if(remain<0) return;
        else if(remain == 0){
            res.push_back(temp);
        }
        else{
            for(int i = start ;i<nums.size();i++){
                if(i > start && nums[i] == nums[i-1])
                    continue;
                temp.push_back(nums[i]);
                backtrack(nums,res,temp,i+1,remain-nums[i]);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector <vector <int> > res ;
        vector<int> temp ;
        sort(nums.begin(),nums.end());
        backtrack(nums,res,temp,0,target);
        return res ;
        
    }
};