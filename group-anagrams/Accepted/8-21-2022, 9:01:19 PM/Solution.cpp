// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    map<string ,vector <string> > m;
    vector <vector <string>>res ;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto &it:strs){
            auto temp = it;
            sort(it.begin(),it.end());
            m[it].push_back(temp);
        }
        for(auto &it:m){
             res.push_back(it.second);
        }
        return res ;
    }
};