// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector <string> res ;
        vector <int> hash1(26,0);
        vector <int> hash2(26,0);
        
        for(int i =0 ;i<words[0].size();i++){
            char ch = words[0][i];
            hash1[ch-'a']++;
        }
        
        for(int i =1 ;i< n;i++){
            
            for(int j =0 ;j< words[i].size();j++){
                char ch = words[i][j];
                hash2 [ch-'a']++;
            }
            for(int k =0 ;k<26;k++){
                hash1[k] = min(hash1[k],hash2[k]);
                hash2[k] =0;
            }
            
        }
        
    
        for(int i =0 ;i<26;i++){
            if(hash1[i] > 0){
                int count = hash1[i];
                while(count --){
                    char x = i+'a';
                    string s ;
                    s= x;
                    res.push_back(s);
                }
            }
        }
        
        return res ;
        
    }
};