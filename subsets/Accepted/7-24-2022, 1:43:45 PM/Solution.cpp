// https://leetcode.com/problems/subsets

class Solution {
public:
   
    int n ,k;
    vector <vector<int> >res;
    void backtrack(int start ,vector<int> &cur,vector<int> &nums){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = start ;i<n;i++){
            cur.push_back(nums[i]);
            backtrack(i+1,cur,nums);
            cur.pop_back();
        }
    }
    
    
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
       n = nums.size();
       vector<int> temp;
       for(k= 0 ;k<n+1;k++){
           backtrack(0,temp,nums);
       } 
        return res ;
        
    }
};