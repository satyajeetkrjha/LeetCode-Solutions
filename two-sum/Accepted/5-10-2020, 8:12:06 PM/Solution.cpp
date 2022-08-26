// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> m;
        vector <int>v;
        for(int i=0;i<nums.size();i++){
            int complement =target-nums[i];
            if(m.find(complement)!=m.end()){
                v.push_back(m[complement]);
                v.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return v;
    }
};