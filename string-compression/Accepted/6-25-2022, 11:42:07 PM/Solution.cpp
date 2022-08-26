// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        
        string res="" ;
        char prev = chars[0];
        int count = 1 ;
        res += prev ;
        for(int i =1 ;i<chars.size();i++){
            char cur = chars[i];
            char prev = chars[i-1];
            if(cur == prev){
                // just increase the count 
                count++;
                
            }
            else {
                // only if count is greater than 1 append to res & make count 1
                if(count > 1){
                    res += to_string(count);
                    count  =1 ;
                }
                res += cur ;
            
                
            }
            
        }
        if(count > 1 ){
            res += to_string(count) ;
        }
        for(int i =0 ;i< res.size();i++){
             chars[i] = res[i];
        }
        
        return res.size();
        
        
        
    }
};