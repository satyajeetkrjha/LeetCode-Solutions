// https://leetcode.com/problems/permutations

class Solution {
public:
    
    vector <vector <int> > ans ;
    
    void backtrack(vector <int> &nums,vector <int> &temp,vector<int> &visited){
        
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i =0 ;i<nums.size();i++){
            if(visited[i] == -1){
                visited[i] =1;
                temp.push_back(nums[i]);
                backtrack(nums,temp,visited);
                visited[i] =-1;
                temp.pop_back();
                
            }
        }
        
    }
    

    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> vis(n,-1);
        
        vector <int> vec;
        backtrack(nums,vec,vis);
        
        return ans ;
    }
};