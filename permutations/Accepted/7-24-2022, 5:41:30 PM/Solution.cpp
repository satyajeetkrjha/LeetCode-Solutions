// https://leetcode.com/problems/permutations

class Solution {
public:
    int n;
    
    vector <vector <int> >  res ;
    void backtrack(vector<int>&nums,vector<int>&visited,vector<int>&cur){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i= 0 ;i<nums.size();i++){
            if(visited[i] == -1){
                visited[i] =1 ;
                cur.push_back(nums[i]);
                backtrack(nums,visited,cur);
                visited[i] =  -1;
                cur.pop_back();
            }
        }
    }
    
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector <int> visited(n,-1);
        vector <int> temp ;
        backtrack(nums,visited,temp);
        return res ;
    }
};