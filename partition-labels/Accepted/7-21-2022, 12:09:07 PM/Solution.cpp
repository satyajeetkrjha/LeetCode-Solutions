// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> res ;
        map <char ,int> m ;
        for(int i =0 ;i< s.size();i++){
            m[s[i]] = i ;
        }
        
        
        int prev = -1 ;
        int maximpact = 0 ;
        for(int i =0 ;i<s.size();i++){
            maximpact = max(maximpact,m[s[i]]);
            if( i == maximpact){
                res.push_back(maximpact - prev);
                prev = maximpact ;
            }
        }
        return res ;
        
    }
};