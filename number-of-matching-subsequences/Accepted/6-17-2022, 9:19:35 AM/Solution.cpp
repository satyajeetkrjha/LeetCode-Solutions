// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    
    
    vector <pair <int ,int> > nextchar[26];
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int res=0;
        for(int i =0 ;i< words.size();i++){
            nextchar[words[i][0]-'a'].push_back({i,0});
        }
        
        for(int i =0 ;i<s.size();i++){
            char ch = s[i] -'a';
            auto cur = nextchar[ch];
            nextchar[ch].clear();
            for(auto[id,pos]:cur){
                if(!words[id][++pos]){
                    res ++;
                }
                else {
                    nextchar[words[id][pos]-'a'].push_back({id,pos}); 
                }
            }
        }
        return res ;
    }
};