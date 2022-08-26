// https://leetcode.com/problems/subsets

class Solution {
public:
     vector<vector<int>>res;
    
     void backtrack(int start ,vector <int>& nums,vector <int>&curr){
        
        for(int i = start ;i<nums.size();i++){
            curr.push_back(nums[i]);
            res.push_back(curr);
            backtrack(i+1,nums,curr);
            curr.pop_back();
        }
    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> curr ;
        res.push_back(curr);
        backtrack(0,nums,curr);
        return res ;
        
    }
};

/*

class Solution {
public:
    
    void backtrack(int p, vector<int> &v, vector<int>& nums, vector<vector<int>> &ans){
       for(int i=p;i<nums.size();i++){ // iterating for every element in nums
            v.push_back(nums[i]); // adding every element in our subset
           ans.push_back(v); // adding this subset to our final answer
            backtrack(i+1,v,nums,ans); // going for more elements to get added to our subset
            v.pop_back(); // popping previously added element to return to the initial state and generate other subsets
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> curr;
       ans.push_back(curr);
       backtrack(0,curr,nums,ans);
       return ans;
    }
};
*/