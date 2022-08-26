// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map <int ,int> m ;
       priority_queue <pair <int ,int> > pq ;
       for(int i =0 ;i<nums.size();i++){
           m[nums[i]]++;
       } 
        for(auto it :m){
            pq.push({it.second ,it.first});
        }
        vector <int> res ;
        int sz = pq.size();
        while(pq.size() > sz-k){
            pair <int ,int> pr = pq.top();
            pq.pop();
            res.push_back(pr.second);
            
        }
        return res ;
        
        
    }
};