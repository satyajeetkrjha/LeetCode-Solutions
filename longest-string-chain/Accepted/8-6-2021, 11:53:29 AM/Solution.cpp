// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    map <string,int> m;
    int dfs(string currentword,set <string>&s){
        if(m.find(currentword)!=m.end()){
            return m[currentword];
        }
        int maxlength = 1;
        // now make all possible strings by deleting one letter 
        for(int i =0 ;i<currentword.size();i++){
            string newword = currentword.substr(0,i) +currentword.substr(i+1);
            if(s.find(newword)!=s.end()){
                int currentlength = 1+ dfs(newword,s);
                maxlength = max(maxlength ,currentlength);
            }
        }
        m[currentword] = maxlength ;
        return maxlength ;
        
        
        
        
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        m.clear();
        set <string> s;
        for(int i =0 ;i<words.size();i++){
            s.insert(words[i]);
        }
        
        int ans =0;
        for(int i =0 ;i<words.size();i++){
            string currentword = words[i];
            ans = max(ans,dfs(currentword,s));
        }
        return ans ;
        
    }
};