// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector <int> res ;
    map<int ,int> m;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0 ;i< nums.size();i++){
            auto val =  nums[i];
            if(m.find(target-val)!=m.end()){
                res.push_back(i);
                res.push_back(m[target-val]);
                return res ;
            }
            m[val] = i ;
        }
        return {} ;
    }
};