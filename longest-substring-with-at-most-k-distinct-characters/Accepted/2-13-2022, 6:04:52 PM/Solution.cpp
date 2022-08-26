// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if(s.size()*k == 0)
            return 0;
        
        int left =0 ;
        int right =0 ;
        
        map <char ,int> m ;
        
        int maxlen = 1;
        
        int sz = s.size();
        
        while(right < sz){
            
            m[s[right]] = right;
            right++;
            
            if(m.size()  == k+1){ 
                int lowestIndex =INT_MAX;
                
                for(auto[element ,index]:  m){
                    lowestIndex = min(lowestIndex,index);
                }
                
                m.erase(s[lowestIndex]); 
                left = lowestIndex+1;
                
            }
            maxlen  = max(maxlen ,right -left);
            
        }
        return maxlen ;
    }
};