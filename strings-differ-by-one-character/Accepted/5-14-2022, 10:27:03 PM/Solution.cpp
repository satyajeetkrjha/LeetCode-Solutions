// https://leetcode.com/problems/strings-differ-by-one-character

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int n = dict.size(); // size of dict 
        int m = dict[0].size();
        vector <int> hash(n+1);
        for(int i =0 ;i<n;i++)
            hash[i] =0;
        int mod = 1e9+7;
        for(int i =0 ;i<n;i++){
            for(int j =0;j<m;j++){
                hash[i] = ((hash[i]*26l + (dict[i][j]-'a'))%mod);
            }
        }
        
      for(int j = m-1 ,mult = 1;j>=0;j--){
           map <int ,vector <int> > m;
          for(int i=0 ;i < n;i++){
              int h = (mod + hash[i]-(long)mult*(dict[i][j]-'a')%mod)%mod;
              auto it = m.find(h);
              if(it!=end(m)){
                  for(auto pi :it->second){
                      if (equal(begin(dict[i]), begin(dict[i]) + j, begin(dict[pi])) 
                       && equal(begin(dict[i]) + j + 1, end(dict[i]), begin(dict[pi]) + j + 1))
                        return true;
                  }
              }
              m[h].push_back(i);
          }
          mult = 26l * mult % mod;
      }
        return false ;
    }                
                           
};