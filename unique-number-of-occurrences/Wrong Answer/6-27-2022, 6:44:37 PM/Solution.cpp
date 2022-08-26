// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    map <int ,int> m;
    bool uniqueOccurrences(vector<int>& arr) {
        
        for(auto &it:arr){
            m[it]++;
        }
        
        int prev = -1;
        int c =0 ;
        for(auto [key,val]:m){
            if( c== 0){
                prev = val ;
                c++;
                continue ;
    
            }
            if(val == prev){
               return false ; 
            }
        }
        return true ;
    }
};