// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    map <char ,int> m ;
    bool isSubsequence(string s, string t) {
        for(auto &it:t){
            m[it]++;
        }
        for(auto &it:s){
            m[it]--;
        }
        
        for(int i =0 ;i<s.size();i++){
            if(m[s[i]]!=0)
                return false;
        }
        return true ;
    }
};