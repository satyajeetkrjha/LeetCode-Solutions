// https://leetcode.com/problems/subsets

class Solution {
public:
    vector <vector <int> > res ;
    int k ;
    void backtrack(vector<int> &nums,vector<int> &temp,int start){
        if(temp.size()  == k){
            res.push_back(temp);
            return ;
        }
        for(int i =start ;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> temp;
        for(k =0 ;k< nums.size()+1 ;k++){
            backtrack(nums,temp,0);
        }
        return res ;
    }
};