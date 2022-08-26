// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        map <int ,int > m;
        
        for(auto &it:nums){
            m[it]++;
        }
        
        int prev = m.begin()->first;
        int count = 1;
        for(auto [key,num]:m){
            
            if(key -prev>k){
                prev = key;
                count++;
            }
        }
        return count ;
        
    }
};