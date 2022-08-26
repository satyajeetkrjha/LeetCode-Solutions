// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    
    
    map <int ,int> count ;
    int res =0;
    int numIdenticalPairs(vector<int>& nums) {
        for(auto &it:nums){
            res+= count[it];
            count[it]++;
           
            
        }
        return res ;
    }
};