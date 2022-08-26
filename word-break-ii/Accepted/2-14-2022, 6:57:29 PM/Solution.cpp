// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
     
        map <string ,vector <string> > m;
        return dfs(s,m,wordDict);
    }
    
    vector <string> dfs(string &s ,map <string,vector<string> >&m,
                       vector<string>& wordDict){
        if(m.find(s)!=m.end()){
            return m[s];
        }
        
        vector <string> res ;
        if(s.size() == 0){
            res.push_back("");
            return res;
        }
        
        for(auto word :wordDict){
            if(s.find(word) == 0){
                string sub = s.substr(word.size(),s.size()-word.size());
                vector <string> substrings = dfs(sub,m,wordDict);
                for(auto substring :substrings){
                    string optionalspace = substring.size() ==0 ?"":" ";
                    res.push_back(word+optionalspace+substring);
                }
            }
        }
        m[s] = res ;
        return res ;
        
        
        
    }
};