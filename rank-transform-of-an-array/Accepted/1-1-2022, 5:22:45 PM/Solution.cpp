// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    
        set <int> s(arr.begin(),arr.end());
        map <int ,int> m;
        int rank=1;
        for(auto it : s){
            m[it] = rank;
            rank++;
        }
        
        for(auto &it: arr){
            it = m[it];
        }
        return arr ;
        
        
    }
};