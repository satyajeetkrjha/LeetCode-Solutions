// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    map <int ,int> m;
    bool uniqueOccurrences(vector<int>& arr) {
        
        for(auto &it:arr){
            m[it]++;
        }
        
        set<int> s;
        for(auto [key,val]:m){
            s.insert(val);
        }
        return s.size() == m.size();
    }
};