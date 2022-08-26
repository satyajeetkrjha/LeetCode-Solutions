// https://leetcode.com/problems/number-of-good-ways-to-split-a-string

class Solution {
public:
   
    
    int numSplits(string s) {
       set <int> forward,backward ;
       int n = s.size();
       int prefix[n];
       int suffix[n];
       for(int i =0 ;i<n;i++){
           forward.insert(s[i]);
           backward.insert(s[n-i-1]);
           prefix[i] = forward.size();
           suffix[n-i-1]= backward.size();
       } 
        int ans = 0 ;
        for(int i =1 ;i<n;i++){
            ans += prefix[i-1] == suffix[i]; 
        }
        return ans ;
        
    }
};