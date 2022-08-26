// https://leetcode.com/problems/subsets


class Solution {
public:
    vector <vector <int>> res ;
    void recur(vector<int> & nums,vector<int> &subsets,int index){
        
        //FIRST PART
        if(index == nums.size()){
            res.push_back(subsets);
            return;
        }
        // Do not include index+1
        recur(nums,subsets,index+1);
        // include index 
        subsets.push_back(nums[index]);
        recur(nums,subsets,index+1);
        
        subsets.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> subset;
        recur(nums,subset,0);
        return res ;
        
    }
};

