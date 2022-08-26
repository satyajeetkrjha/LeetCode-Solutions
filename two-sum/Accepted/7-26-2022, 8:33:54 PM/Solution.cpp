// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map <int ,int> m;
        vector <int> res ;
        
        for(int i =0 ;i<nums.size();i++){
            int x = nums[i];
            
            if(m.find(target-x)!=m.end()){
                res.push_back(i);
                res.push_back(m[target-x]);
                break;
            }

            m[x] = i;
        }
        return res ;
        
    }
};