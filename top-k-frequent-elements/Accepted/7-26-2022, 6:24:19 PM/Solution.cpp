// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    
    map <int,int> m;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sz = nums.size();
        for(int i =0 ;i<sz;i++){
            m[nums[i]]++;
        }
        vector<vector <int> > freq;
        freq.resize(sz+1);
        
        for(auto &[key,value]:m){
            freq[value].push_back(key);
        }
        vector <int> res ;
        for(int i = sz ;i>=0 ;i--){
             vector <int> temp = freq[i];
             for(auto &it:temp){
                 res.push_back(it);
                 if(res.size() == k)
                     return res ;
             }
        }
        
        return  res ;
        
    }
};