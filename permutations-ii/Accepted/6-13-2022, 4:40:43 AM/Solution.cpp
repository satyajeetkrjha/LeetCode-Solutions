// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    
    vector <vector <int> > ans ;
    
    void backtrack(vector<int>nums,vector<int> &temp,vector<int> &visited){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0 ;i< nums.size();i++){
          if(visited[i] ==1 || (i>0 && nums[i] == nums[i-1] && visited[i-1]==1))
              continue;
            else{
                visited[i] = 1;
                temp.push_back(nums[i]);
                backtrack(nums,temp,visited);
                visited[i] = -1;
                temp.pop_back();
            }
        }
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector <int> visited(n,-1);
        vector <int> temp;
        backtrack(nums,temp,visited);
        return ans ;
    }
};