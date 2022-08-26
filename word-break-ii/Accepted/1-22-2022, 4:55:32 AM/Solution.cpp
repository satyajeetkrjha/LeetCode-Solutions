// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string ,vector<string>>m;
        return dfs(s,wordDict,m);
    }
    
    vector<string> dfs(string s ,vector<string>& wordDict,map<string ,vector<string>>&m){
        if(m .find(s) != m.end()){
            return m[s];
        }
        vector <string> res ;
        
        if(s.length() == 0){
            res.push_back("");
            return res ;
        }
        
        for(auto word : wordDict){
            // string s starts with the word 
            if(s.find(word) == 0){
                string sub = s.substr(word.size(),(s.size()-word.size()));
                //cout <<"sub is "<< sub << endl;
                vector <string> substrings = dfs(sub,wordDict,m);
                for(auto substring:substrings){
                  string optionalspace = substring.size() == 0 ? "":" ";
                    res.push_back(word+optionalspace+substring);
                }
            }
        }
        m[s]= res ;
        return res ;        
    }

};