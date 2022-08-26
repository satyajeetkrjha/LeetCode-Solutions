// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map <int,int> m;
        vector<int> v;
       priority_queue<pair<int,int>> p;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            p.push({i.second,i.first}); // {count,key}
        }
        for(int i=1;i<=k;i++){
            v.push_back(p.top().second);
            p.pop();
        }
        return v ;
        
    }
};