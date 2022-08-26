// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int ,int> m ;
        for(int i =0 ;i<nums.size();i++){
            int x = nums[i];
            m[x]++;
        }
        
        priority_queue <pair <int ,int> > pq ;
        for(auto[element ,frequency]:m){
            pq.push({frequency,element});
        }
        
        // to do
        vector <int> res ;
        int sz = pq.size();
        for(int i =0 ;i<k;i++){
            auto ele = pq.top();
            pq.pop();
            res.push_back(ele.second);
        }
        return res ;
        
        
        
        
    }
};