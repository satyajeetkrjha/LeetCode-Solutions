// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector <vector <int> > res ;
    
    void backtrack(int start ,vector <int> &curr ,vector <int> &nums){
        for(int i = start ;i<nums.size();i++){
            if((i>start) &&  (nums[i] == nums[i-1])){
                continue;
            }
            curr.push_back(nums[i]);
            res.push_back(curr);
            backtrack(i+1,curr,nums);
            curr.pop_back();
        }
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     sort(nums.begin(),nums.end());
      vector <int> curr;
      res.push_back(curr);
      backtrack(0,curr,nums);
        return res ;
  
        
        
    }
};