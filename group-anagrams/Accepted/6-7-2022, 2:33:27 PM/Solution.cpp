// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    map <string ,vector <string> > m;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        for(int i =0 ;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }
        vector <vector<string> > res ;
        for(auto it:m){
            vector <string> temp = it.second;
            res.push_back(temp);
        }
        return res ;
        
    }
};