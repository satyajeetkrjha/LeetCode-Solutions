// https://leetcode.com/problems/subsets

class Solution {
public:
    
    vector <vector <int> > res ;
    void backtrack(vector <int> nums,int start,vector <int> &cur){
        for(int i = start ;i<nums.size();i++){
            cur.push_back(nums[i]);
            res.push_back(cur);
            backtrack(nums,i+1,cur);
            cur.pop_back();
        }
    }
    
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
     
     vector <int> cur ;
     res.push_back(cur);
     backtrack(nums,0,cur);
     return res ;   
        
    }
};