// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    
    map <string ,int> m;
    vector<string> topKFrequent(vector<string>& words, int k) {
        int sz = words.size();
        for(int i =0 ;i<sz;i++){
            m[words[i]]++;
        }
        
        vector <vector <string>> freq;
        freq.resize(sz+2);
        
        for(auto[key,value]:m){
            freq[value].push_back(key);
        }
        
        /*
        for(auto [key,value]:m){
            cout << key << " :"<< value << endl;
        }
        */
        vector <string> res ;
    
        for(int i = sz;i>=0 ;i--){
            vector <string> temp = freq[i] ;
            if(temp.size() == 0) continue ;
            sort(temp.begin(),temp.end());
            for(auto &it:temp){
                res.push_back(it);
                if(res.size() == k){
                    return res ;
                }
            }
           
        }
        return res ;
    }
};