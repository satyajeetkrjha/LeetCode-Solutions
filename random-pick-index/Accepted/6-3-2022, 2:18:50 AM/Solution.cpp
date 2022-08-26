// https://leetcode.com/problems/random-pick-index

class Solution {
public:
    map <int ,vector <int> > indices ;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i =0 ;i< n;i++){
            indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int sz = indices[target].size();
        vector <int> vec = indices[target];
        int random = rand() % sz ;
        return vec[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */