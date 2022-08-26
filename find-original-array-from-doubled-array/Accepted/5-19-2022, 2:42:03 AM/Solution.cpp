// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    map <int ,int> m;
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector <int> res ;
        
        if(changed.size() % 2==1){
            return {} ;
        }
        for(int i =0 ;i< changed.size();i++){
            m[changed[i]]++;
        }
        
        sort(changed.begin(),changed.end());
        
        for(int i =0 ;i< changed.size();i++){
            int num = changed[i];
            int twice = num*2 ;
            
            /*
             We reduced the frequency of num anf frequency of
              2*num in the array .Since we already reduced frequency of double so if we encountee it's doubale again then it's frequemcy is already reduced to zero for m[num] == 0 ,we don't do anything and this is a crucial step .
        
            */
            
            
            if(m[num] == 0) continue ;
            
            if(m[twice] == 0){
                return {} ;
            }
            m[twice]--;
            m[num] --;
            res.push_back(num);
        }
        return res ;
    }
};