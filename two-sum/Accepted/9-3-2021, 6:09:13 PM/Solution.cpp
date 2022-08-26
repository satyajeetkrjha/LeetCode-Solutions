// https://leetcode.com/problems/two-sum

class Solution {
public:
    map <int ,int> m ; // values and indices
    vector <int> v;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0 ;i<nums.size();i++){
            int complement = target - nums[i];
            // if complement exists in the map
            if(m.find(complement)!= m.end()){
                v.push_back(i);
                v.push_back(m[complement]);
            }
            m[nums[i]] = i;
        }
        return v;
    }
};