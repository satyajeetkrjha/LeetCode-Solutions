// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void backtrack (vector <vector <int> > &res ,vector <int>&temp ,vector <int> &nums,int start ,int remain){
        if(remain <0) return ;
        else if(remain == 0){
            res.push_back(temp);
        }
        else{
            for(int i = start;i<nums.size();i++){
                temp.push_back(nums[i]);
                backtrack(res,temp,nums,i,remain-nums[i]);
                temp.pop_back();
            }
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector <vector <int> > res ;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        backtrack(res,temp,nums,0,target);
        return res ;
        
        
    }
    
};