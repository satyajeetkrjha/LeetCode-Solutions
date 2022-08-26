// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        
        map <char ,int> m ;
        for(int i=0 ;i<s.size();i++){
            char c = s[i];
            m[c]++;
        }
        unordered_set <int> seen ;
        
        int ans =0;
        for(auto[k,v]:m){
            
            while(seen.find(v)!=seen.end()){
                v--;
                ans ++;
            }
            if(v > 0) seen.insert(v);
        }
        /*
        for(auto it :seen){
            cout << it << " ";
        }
        cout << endl;
        */
        return ans ;
        
        
        
        
    }
};