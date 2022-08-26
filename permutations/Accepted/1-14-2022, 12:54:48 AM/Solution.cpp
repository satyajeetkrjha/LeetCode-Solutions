// https://leetcode.com/problems/permutations

class Solution {
public:
    
    void backtrack(vector <vector<int>>&res,vector<int>&temp,vector<int>&nums){
        if(temp.size() == nums.size()){
            res.push_back(temp);
        }
        else{
            for(int i =0 ;i<nums.size();i++){
                if(find(temp.begin(),temp.end(),nums[i]) != temp.end()){
                    continue;
                }
                temp.push_back(nums[i]);
                backtrack(res,temp,nums);
                temp.pop_back();
            }
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> res;
        vector <int> temp ;
        backtrack(res,temp ,nums);
        return res ;
        
    }
};