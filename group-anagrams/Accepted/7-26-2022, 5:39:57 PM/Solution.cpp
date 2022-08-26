// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    map <string ,vector <string> > m;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
           int sz = strs.size();
        for(int i =0 ;i<sz;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        
        vector <vector <string > > res ;
        for(auto &it:m){
            res.push_back(it.second);
        }
        return res ;
    }
};