// https://leetcode.com/problems/shuffle-string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res;
        map <int,char> m;
        for(int i =0 ;i<indices.size();i++){
            m[indices[i]] = s[i];
        }
        for(auto it :m){
            res += it.second;
        }
        return res ;
        
    }
};