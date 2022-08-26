// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    
    map <char,int> m ;

    set <int> seen ;
    
    int minDeletions(string s) {
        
        for(int i =0 ;i<s.size();i++){
            char c =s[i];
            m[c]++;
        }
        int ans =0;
        for(auto[k,v]: m){
            
            while(seen.find(v)!=seen.end()){
                v--;
                ans ++;
            }
            if(v >0) seen.insert(v);
        }
        return ans ;
        
        
    }
};