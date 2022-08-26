// https://leetcode.com/problems/subsets

class Solution {
public:
    vector <vector <int> > ans;
    vector <int> v;
    void recur(vector <int> &nums,int index,int n){
        if(index ==n){
            ans.push_back(v);
            return ;
        }
        v.push_back(nums[index]);
        recur(nums,index+1,n);
        if(v.size()>0)
         v.pop_back();
        recur(nums,index+1,n);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        recur(nums,0,n);
        return ans;
    }
};