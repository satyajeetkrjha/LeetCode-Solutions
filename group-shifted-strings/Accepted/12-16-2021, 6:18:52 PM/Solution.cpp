// https://leetcode.com/problems/group-shifted-strings

class Solution {
public:
    
    string key(string s ){
        string res ="";
        for(int i =1 ;i<s.size();i++){
            int diff = s[i]-s[i-1];
            if(diff <0){
                diff +=26;
            }
            res+=to_string(diff)+"#";
        }
        res+=".";
        return res ;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
      
        map <string ,vector <string> > m;
        
       for(int i=0 ;i<strings.size();i++){
           string s = strings[i];
           string keyval = key(s);
           m[keyval].push_back(s);
       
       }
        
        vector < vector <string> > res ;
        
        for(auto it :m){
            vector <string> temp = it.second ;
            res.push_back(temp);
        }
        return res ;
    }
};