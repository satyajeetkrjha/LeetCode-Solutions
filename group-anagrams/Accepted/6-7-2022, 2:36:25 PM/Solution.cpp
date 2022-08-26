// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map <string ,vector <string> > m ;
        vector <vector <string> > res ;
        for(int i =0 ;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }
        
        for(auto it:m){
            res.push_back(it.second);
        }
        return res ;
        
        
    }
};