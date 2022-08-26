// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    map <char ,int> m ;
    string frequencySort(string s) {
        for(int i =0 ;i< s.size();i++){
            char ch = s[i];
            m[ch]++;
        }
        vector <vector<char>> freq;
        int sz = s.size()+1;
        freq.resize(sz+2);
        
        for(auto [key,value]:m){
            freq[value].push_back(key);
        }
        string res ;
        for(int i = sz; i>=0 ;i--){
            vector<char> temp =freq[i];
            if(temp.size() == 0)
                continue;
            for(auto &it:temp){
                for(int k = 0 ;k<i;k++){
                    res += it;
                }
            }
        }
        return res ;
        
        
    }
};