// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int ,int> m ;
        vector <vector <int> > bucket ;
        int n = nums.size();
        bucket.resize(n+1);
        for(auto &it:nums){
            m[it]++;
        }
        for(auto[key,val]:m){
            bucket[val].push_back(key);
        }
        vector <int> res ;
        int sz = bucket.size();
        for(int i = sz-1;i>=0 ;i--){
            auto temp = bucket[i];
            for(auto &it:temp){
                res.push_back(it);
                if(res.size()== k)
                    return res ;
            }
        }
        return res ;
        
        
        
    }
};